#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
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
#define GREEN "\033[32m"



// Tabela 1–100 e função para imprimir com cores
bool marcados[101] = {false};

void printTabela() {
    cout << WHITE;
    cout << "+-------------------------------------------------------------------------------+\n";
    for (int i = 1; i <= 100; i++) {
        if (i % 10 == 1) cout << "| ";

        if (marcados[i])
            cout << RED << i << "\t" << WHITE;
        else
            cout << i << "\t";

        if (i % 10 == 0) cout << "|\n";
    }
    cout << "+-------------------------------------------------------------------------------+\n";
}



// Classe do cartão de Bingo
class BingoCard {
private:
    vector<vector<int>> grid;

public:
    BingoCard() {
        grid.resize(5, vector<int>(5, 0));
    }

    void generate() {
        vector<pair<int, int>> ranges = {
            {1, 20}, {21, 40}, {41, 60}, {61, 80}, {81, 100}
        };

                default_random_engine(time(0));

        for (int col = 0; col < 5; col++) {
            vector<int> numbers;
            for (int n = ranges[col].first; n <= ranges[col].second; n++)
                numbers.push_back(n);

            shuffle(numbers.begin(), numbers.end(), g);

            for (int row = 0; row < 5; row++)
                grid[row][col] = numbers[row];
        }

        grid[2][2] = 0; // espaço livre
    }

    void saveToFile(int num) {
        string filename = "Carta_" + to_string(num) + ".txt";
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Erro ao criar o ficheiro " << filename << endl;
            return;
        }

        file << " B\t I\t N\t G\t O\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 && j == 2)
                    file << "**\t";
                else
                    file << grid[i][j] << "\t";
            }
            file << "\n";
        }
        file.close();
    }
};

// Classe para sorteio de bolas
class BingoDrawMachine {
private:
    vector<int> bolas;
    vector<int> ultimas5;
    int index;
    int ultima;

public:
    BingoDrawMachine() {
        for (int i = 1; i <= 100; i++)
            bolas.push_back(i);

        
        shuffle(bolas.begin(), bolas.end(),
        default_random_engine(time(0)));

        index = 0;
        ultima = -1;
    }

    int drawNext() {
        if (index >= 100)
            return -1; // todas as bolas sorteadas

        int atual = bolas[index++];
        ultimas5.insert(ultimas5.begin(), atual);
        if (ultimas5.size() > 5)
            ultimas5.pop_back();

        ultima = (ultimas5.size() > 1 ? ultimas5[1] : -1);
        return atual;
    }

    void showStatus(int atual) {
        system("clear");
    
        // Marca o número sorteado
        if (atual >= 1 && atual <= 100)
            marcados[atual] = true;
    
        cout << "\n--------------------------------\n";
        cout << "Bola atualmente sorteada: " << GREEN << atual << RESET "\n";
    
        if (ultima != -1)
            cout << "Última bola sorteada: " << GREEN << ultima << RESET "\n";
        else
            cout << "Última bola sorteada: " << RED <<"nenhuma\n" << RESET;
    
        cout << "Últimas 5 bolas: ";
        for (int n : ultimas5)
            cout << GREEN << n << " " << RESET;
        cout << "\n\n";
    
        // Mostra a tabela atualizada
        printTabela();
    }
    
};

// Função principal
int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Uso: ./generatecards [numero_de_cartoes]\n";
        return 1;
    }

  //stoi string para inteiro
    int numCards = stoi(argv[1]);
    if (numCards < 1 || numCards > 500) {
        cerr << "Número de cartões deve ser entre 1 e 500.\n";
        return 1;
    }

    // Gera e salva os cartões
    vector<BingoCard> cards(numCards);
    for (int i = 0; i < numCards; i++) {
        cards[i].generate();
        cards[i].saveToFile(i + 1);
    }

    system("clear");

    cout << "\nTodos os cartões foram gerados e salvos.\n";

    // Sorteio de números
    BingoDrawMachine machine;

    cout << "\nSelecione o modo de sorteio:\n";
    cout << "1 - Automático (2 segundos)\n";
    cout << "2 - Manual (pressione Enter)\n";
    int modo;
    cin >> modo;
    cin.ignore();

    while (true) {
        if (modo == 2) {
            cout << "\nPressione Enter para sortear...";
            cin.ignore();
        } else {
            this_thread::sleep_for(chrono::seconds(2));
        }

        int atual = machine.drawNext();
        if (atual == -1) {
            cout << "\nTodas as bolas foram sorteadas!\n";
            break;
        }

        machine.showStatus(atual);
    }

    return 0;
}
