#include <iostream>
#include <cstdlib>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

struct Casas {
    bool jogador1 = false;
    bool jogador2 = false;
};

Casas myMatrix[5][6];

string estado(Casas x){
    if(x.jogador1 && !x.jogador2) return string(RED) + "🔴   " + RESET;
    if(!x.jogador1 && x.jogador2) return string(BLUE) + "🔵   " + RESET;
    if(x.jogador1 && x.jogador2) return string(RED) + "🔴🔵 " + RESET;
    return "     ";
}

// Espera o jogador pressionar ENTER (sem usar novas libs)
void esperarEnter(){
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();   // limpa qualquer enter anterior
    cin.get();      // espera ENTER
}

// Função que rola o dado
int Dado(int jogador) {
    cout << "\nVez do jogador " << (jogador == 1 ? "🔴" : "🔵") << endl;
    cout << "Pressione ENTER para rolar o dado 🎲";
    cin.ignore();
    cin.get();
    int valor = rand() % 6 + 1;
    cout << YELLOW << "\nSaiu o número: " << valor << RESET << endl;
    cout << "Pressione ENTER para avançar as casas...";
    cin.get();
    return valor;
}

// Movimenta o jogador
int andarCasas(Casas m[5][6], bool jogador1, int valor){
    int pospino = -1;

    for(int i = 0; i < 5; i++ ){
        for(int j = 0; j < 6; j++ ){
            if (jogador1 && m[i][j].jogador1){
                pospino = i * 6 + j;
                m[i][j].jogador1 = false;
            }
            else if(!jogador1 && m[i][j].jogador2){
                pospino = i * 6 + j;
                m[i][j].jogador2 = false;
            }
        }
    }

    if(pospino == -1) pospino = 0;

    int novapos = pospino + valor;
    if(novapos > 29) novapos = 29;

    int linhanv = novapos / 6;
    int colunanv = novapos % 6;

    if(jogador1) m[linhanv][colunanv].jogador1 = true;
    else m[linhanv][colunanv].jogador2 = true;

    return novapos;
}

void CasasEspeciais(Casas m[5][6], bool jogador1, int &pos, bool &pularVez, bool &esperar, bool &jogarDeNovo){
    // Cálculo da linha e coluna
    int linha = pos / 6;
    int coluna = pos % 6;

    // Identifica número da casa (1–30)
    int casa = pos + 1;

    jogarDeNovo = false; // padrão

    // 🟥 Casa 5: perde a vez
    if (casa == 5) {
        pularVez = true;
        cout << RED << "\nPerdeu a vez! 😢" << RESET << endl;
    }

    // 🟦 Casa 10: volta 3 casas
    else if (casa == 10) {
        int novaPos = max(0, pos - 3);
        if (jogador1) {
            m[linha][coluna].jogador1 = false;
            m[novaPos / 6][novaPos % 6].jogador1 = true;
        } else {
            m[linha][coluna].jogador2 = false;
            m[novaPos / 6][novaPos % 6].jogador2 = true;
        }
        pos = novaPos;
        cout << BLUE << "\nVoltou 3 casas! ⬅️" << RESET << endl;
    }

    // 🟩 Casa 15: avança 3 casas
    else if (casa == 15) {
        int novaPos = min(29, pos + 3);
        if (jogador1) {
            m[linha][coluna].jogador1 = false;
            m[novaPos / 6][novaPos % 6].jogador1 = true;
        } else {
            m[linha][coluna].jogador2 = false;
            m[novaPos / 6][novaPos % 6].jogador2 = true;
        }
        pos = novaPos;
        cout << GREEN << "\nAvançou 3 casas! ➡️" << RESET << endl;
    }

    // 🟨 Casa 20: joga novamente
    else if (casa == 20) {
        jogarDeNovo = true;
        cout << YELLOW << "\nJoga novamente! 🎲" << RESET << endl;
    }

    // ⬛ Casa 25: espera ser ultrapassado
    else if (casa == 25) {
        esperar = true;
        cout << "\033[90m\nDeve esperar até ser ultrapassado... ⏳" << RESET << endl;
    }
}


void tabuleiro(Casas m[5][6]) {
    int contador = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) cout << GREEN "+-------";
        cout << "+\n" RESET;
        for (int j = 0; j < 6; j++) {
            cout << GREEN "| " RESET;
            if (contador < 10)
                cout << YELLOW << contador << "     " << RESET;
            else
                cout << YELLOW << contador << "    " << RESET;
            contador++;
        }
        cout << GREEN "|\n" RESET;
        for (int j = 0; j < 6; j++) {
            cout << GREEN "| " RESET << estado(m[i][j]) << GREEN " " RESET;
        }
        cout << GREEN "|\n" RESET;
    }
    for (int j = 0; j < 6; j++) cout << GREEN "+-------";
    cout << "+\n" RESET;
}

bool pularVez1 = false;
bool pularVez2 = false;
bool esperar1 = false;
bool esperar2 = false;

int main(){
    system("clear");
    srand(time(0));

    myMatrix[0][0].jogador1 = true;
    myMatrix[0][0].jogador2 = true;

    int pos1 = 0, pos2 = 0;
    bool jogarDeNovo;

    while (true){
        // ===== JOGADOR 1 =====
        if (!pularVez1 && !esperar1) {
            do {
                system("clear");
                tabuleiro(myMatrix);
                int valor1 = Dado(1);
                pos1 = andarCasas(myMatrix, true, valor1);
                jogarDeNovo = false;
                CasasEspeciais(myMatrix, true, pos1, pularVez1, esperar1, jogarDeNovo);
                system("clear");
                tabuleiro(myMatrix);
                if (myMatrix[4][5].jogador1) {
                    cout << "\n🔴 Jogador 1 venceu! 🎉\n";
                    return 0;
                }
            } while (jogarDeNovo);
        } else {
            if (pularVez1) {
                cout << RED << "\n🔴 Jogador 1 perdeu a vez!" << RESET << endl;
                pularVez1 = false;
            } else if (esperar1 && pos2 > pos1) {
                cout << GREEN << "\n🔴 Jogador 1 já foi ultrapassado e pode jogar de novo!" << RESET << endl;
                esperar1 = false;
            } else {
                cout << "\033[90m\n🔴 Jogador 1 está à espera..." << RESET << endl;
            }
            cout << "\nPressione ENTER...";
            cin.ignore();
            cin.get();
        }

        // ===== JOGADOR 2 =====
        if (!pularVez2 && !esperar2) {
            do {
                system("clear");
                tabuleiro(myMatrix);
                int valor2 = Dado(2);
                pos2 = andarCasas(myMatrix, false, valor2);
                jogarDeNovo = false;
                CasasEspeciais(myMatrix, false, pos2, pularVez2, esperar2, jogarDeNovo);
                system("clear");
                tabuleiro(myMatrix);
                if (myMatrix[4][5].jogador2) {
                    cout << "\n🔵 Jogador 2 venceu! 🎉\n";
                    return 0;
                }
            } while (jogarDeNovo);
        } else {
            if (pularVez2) {
                cout << BLUE << "\n🔵 Jogador 2 perdeu a vez!" << RESET << endl;
                pularVez2 = false;
            } else if (esperar2 && pos1 > pos2) {
                cout << GREEN << "\n🔵 Jogador 2 já foi ultrapassado e pode jogar de novo!" << RESET << endl;
                esperar2 = false;
            } else {
                cout << "\033[90m\n🔵 Jogador 2 está à espera..." << RESET << endl;
            }
            cout << "\nPressione ENTER...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
