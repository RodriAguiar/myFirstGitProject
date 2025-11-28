#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BGGRAY "\033[100m"

int cordX, cordY;
bool vertical = 0;

struct Nums {
    bool boat;
    bool shot;
};

struct Boat {
    string nome;
    int tamanho;
    Nums nums;
};

Boat barcos[]{
    {"AircraftCarrier",5,{0,0}},
    {"Battleship",4,{0,0}},
    {"Cruiser",3,{0,0}},
    {"Submarine",3,{0,0}},
    {"Destroyer",2,{0,0}}
};

Nums myMatrixA[10][10];
Nums myMatrixB[10][10];

// Função para estado visual da célula
string estado(Nums x, bool oculto = false) {
    if(x.boat && x.shot) return string(RED)+"[X]"+RESET;
    if(!x.boat && x.shot) return string(CYAN)+" W "+RESET;
    if(x.boat && !x.shot && !oculto) return string(BGGRAY)+"[ ]"+RESET;
    return string(BLUE)+" ~ "+RESET;
}

// Linha do tabuleiro
string linhaEstado(Nums matrix[10][10], int y, bool oculto=false) {
    string linha = "";
    for(int i=0; i<10; i++) linha += estado(matrix[i][y], oculto);
    return linha;
}

// Direção-barco
void direcao(bool &vertical,Boat &barcos){  
    if(vertical==0){
        for(int i=0;i<barcos.tamanho;i++){
            cout<<"[*]";
        }
    }else if(vertical==1){
        for(int i=0;i<barcos.tamanho;i++){
            cout<<"[*]"<<endl;
        }
    }
}

// Tabela do jogador atual (durante posicionamento)
void table(Nums Player[10][10], int jogador) {
    cout << YELLOW << "   1  2  3  4  5  6  7  8  9  10" << RESET << endl;
    cout << WHITE << " +------------------------------+" << RESET << endl;
    for(int y=0;y<10;y++)
        cout << char('A'+y) << WHITE << "|" << linhaEstado(Player,y,false) << endl;
    cout << WHITE << " +------------------------------+" << RESET << endl;
    cout << " PLAYER " << jogador << endl;
    direcao(vertical,barcos[0]);
    cout << YELLOW << "\n[1] Rotacionar  " << RESET << endl;

}

// Tabela oculta (histórico de tiros)
void tableHidden(Nums Player[10][10], int jogador){
    cout << YELLOW << "   1  2  3  4  5  6  7  8  9  10" << RESET << endl;
    cout << WHITE << " +------------------------------+" << RESET << endl;
    for(int y=0;y<10;y++){
        cout << char('A'+y) << WHITE << "|";
        for(int x=0;x<10;x++){
            if(Player[x][y].shot && Player[x][y].boat)
                cout << RED << "[X]" << RESET;
            else if(Player[x][y].shot)
                cout << CYAN << " W " << RESET;
            else
                cout << BLUE << " ~ " << RESET;
        }
        cout << endl;
    }
    cout << WHITE << " +------------------------------+" << RESET << endl;
    cout << " PLAYER " << jogador << endl;
}

// Ler coordenadas tipo "A5"
void playerAct(int& cordX,int& cordY){
    string input;
    cout << "You: ";
    cin >> input;

    if (input == "1") {
        vertical = !vertical;
        cout << "Direção alterada para: "
             << (vertical ? "Vertical" : "Horizontal") << endl;
        cordX = -2;
        cordY = -2;
        return;
    }

    if (input[0] == 'a' || input[0] == 'A') cordY = 0;
    else if (input[0] == 'b' || input[0] == 'B') cordY = 1;
    else if(input[0] == 'c' || input[0] =='C') cordY = 2;
    else if(input[0] == 'd' || input[0] =='D') cordY = 3;
    else if(input[0] == 'e' || input[0] =='E') cordY = 4;
    else if(input[0] == 'f' || input[0] == 'F') cordY = 5;
    else if(input[0] == 'g' || input[0] == 'G') cordY = 6;
    else if(input[0] == 'h' || input[0] == 'H') cordY = 7;
    else if(input[0] == 'i' || input[0] == 'I') cordY = 8;
    else if(input[0] == 'j' || input[0] == 'J') cordY = 9;
    else cordY=-1;

    switch (input.size()){
        case 2: cordX = input[1]-'1'; break;
        case 3: if(input[1]=='1' && input[2]=='0') cordX=9; else cordX=-1; break;
        default: cordX=-1; break;
    }
}

// Função que verifica se o barco pode ser colocado sem sobreposição
bool podeColocar(Nums MyMatrix[10][10], int cordX, int cordY, Boat barco) {
    if(vertical){
        if(cordY + barco.tamanho > 10) return false;
        for(int i=0; i<barco.tamanho; i++)
            if(MyMatrix[cordX][cordY+i].boat) return false;
    } else {
        if(cordX + barco.tamanho > 10) return false;
        for(int i=0; i<barco.tamanho; i++)
            if(MyMatrix[cordX+i][cordY].boat) return false;
    }
    return true;
}

// Colocar barco na matriz (sem sobreposição)
void diresao(Nums MyMatrix[10][10], int cordX, int cordY, Boat barco){
    if(!podeColocar(MyMatrix, cordX, cordY, barco)){
        cout << RED << "❌ O barco não pode ser colocado aqui! Há outro barco ou ultrapassa o limite." << RESET << endl;
        return;
    }

    if(vertical){
        for(int i=0;i<barco.tamanho;i++)
            MyMatrix[cordX][cordY+i].boat = true;
    } else {
        for(int i=0;i<barco.tamanho;i++)
            MyMatrix[cordX+i][cordY].boat = true;
    }
}

// Verificar se todos os barcos afundaram
bool allBoatsSunk(Nums MyMatrix[10][10]){
    for(int y=0;y<10;y++)
        for(int x=0;x<10;x++)
            if(MyMatrix[x][y].boat && !MyMatrix[x][y].shot) return false;
    return true;
}

// Atirar — grava tiros e evita repetir
bool shotact(Nums MyMatrix[10][10], int cordX,int cordY){
    if(cordX<0||cordX>=10||cordY<0||cordY>=10) return false;
    if(MyMatrix[cordX][cordY].shot){
        cout<<RED<<"\nJá atiraste aqui! Tenta outra."<<RESET<<endl;
        return false;
    }
    MyMatrix[cordX][cordY].shot=true;
    return true;
}

int main(){
        //Rodrigo Aguiar e Rodrigo Martins
    cout << YELLOW << "\n--- BATALHA NAVAL 2 JOGADORES ---\n" << RESET;

    // ===== POSICIONAMENTO =====
    for(int jogador=1;jogador<=2;jogador++){
        Nums (*matriz)[10] = (jogador==1)?myMatrixA:myMatrixB;
        cout << "\n" << CYAN << "Jogador "<<jogador<<", coloque seus barcos!"<<RESET<<endl;
        cout << "O outro jogador não pode olhar. Pressiona ENTER...";
        cin.ignore(); cin.get();

        int barcoAtual=0;
        while(barcoAtual<5){
            system("clear");
            table(matriz,jogador);
            cout << "Colocando: " << YELLOW << barcos[barcoAtual].nome << RESET
                 << " (" << barcos[barcoAtual].tamanho << " espaços)" << endl;

            playerAct(cordX,cordY);
            if(cordX==-2 && cordY==-2) continue; // só rodou

            if(cordX>=0 && cordY>=0 && cordX<10 && cordY<10){
                if(!podeColocar(matriz, cordX, cordY, barcos[barcoAtual])){
                    cout << RED << "❌ Sobreposição detectada! Escolhe outra posição." << RESET << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    continue;
                }

                diresao(matriz,cordX,cordY,barcos[barcoAtual]);
                system("clear");
                table(matriz,jogador); // mostra tabuleiro atualizado
                barcoAtual++;
            } else {
                cout<<RED<<"Coordenada inválida! Tente novamente."<<RESET<<endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }

        cout << CYAN << "\nJogador "<<jogador<<" terminou o posicionamento!"<<RESET<<endl;
        cout << "Pressiona ENTER para passar para o próximo jogador...";
        cin.ignore(); cin.get();

        system("clear");
        tableHidden(matriz,jogador); // tela neutra
        cout << "Pressiona ENTER para continuar...";
        cin.get();
    }

    // ===== FASE DE ATAQUE =====
    bool gameover=false;
    while(!gameover){
        // Jogador 1
        system("clear");
        cout << "\n" << CYAN << "PLAYER 1, é a tua vez!" << RESET << endl;
        tableHidden(myMatrixB,2);
        bool valido=false;
        while(!valido){
            playerAct(cordX,cordY);
            valido = shotact(myMatrixB,cordX,cordY);
        }
        if(allBoatsSunk(myMatrixB)){ cout << YELLOW << "🏆 PLAYER 1 VENCEU!" << RESET << endl; break; }

        cout << CYAN << "\nPressiona ENTER para passar ao jogador 2..." << RESET << endl;
        cin.ignore(); cin.get();
        system("clear");
        cout << RED "Esperando 1 segundo para mudar de jogador." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");


        // Jogador 2
        cout << "\n" << CYAN << "PLAYER 2, é a tua vez!" << RESET << endl;
        tableHidden(myMatrixA,1);
        valido=false;
        while(!valido){
            playerAct(cordX,cordY);
            valido = shotact(myMatrixA,cordX,cordY);
        }
        if(allBoatsSunk(myMatrixA)){ cout << YELLOW << "🏆 PLAYER 2 VENCEU!" << RESET << endl; break; }

        cout << CYAN << "\nPressiona ENTER para passar ao jogador 1..." << RESET << endl;
        cin.ignore(); cin.get();
        system("clear");
        cout << RED "Esperando 1 segundo para mudar de jogador." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    } 

    return 0;
}