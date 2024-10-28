#include <iostream>
using namespace std;

int main() {
    // Criação de um array para armazenar os números pares
    int array[10]; // Existem 10 números pares de 1 a 20
    int index = 0;

    // Preenchendo o array com números pares de 1 a 20
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) { // Verifica se o número é par
            array[index] = i;
            index++;
        }
    }

    // Exibindo os números pares armazenados no array
    cout << "Números pares de 1 a 20:" << endl;
    for (int i = 0; i < index; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
