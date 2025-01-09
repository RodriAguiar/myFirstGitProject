#include <iostream>
using namespace std;

 string bebidas[3][2] = {
        {"Iced Tea", "n.º:01"},
        {"Coca Cola", "n.º:02"},
        {"Fanta Laranja", "n.º:03"}
    };

int produto;   
float dinheiro;
float resto;

int main () {
cout << "Podes comprar os seguintes produtos:" << endl;

for (int i = 0; i < 3; i++) {
        cout << bebidas[i][0] << " | " << bebidas[i][1] << endl;
    }

cout << "Seleciona o número do produto " << endl;
cin >> produto;

if (produto == 01 || 1 ){
    cout << "O seu produto custa: 1€" << endl;
    cout << "Porfavor insira o dinheiro" << endl;
    cin >> dinheiro;
    if (dinheiro - 1 != 0 ){
        cout << "Ainda falta " << 1 - dinheiro  << " para pagar. Porfavor insira o resto do dinheiro." << endl; 
        cin >> resto;
    }
        if (dinheiro == 1 || resto ){
            cout << "Agradecemos pela sua compra continuações de um bom dia" << endl;
        }
}
else if (produto == 02 || 2)
{
    cout << "O seu produto custa: 1€" << endl;
    cout << "Porfavor insira o dinheiro" << endl;
    cin >> dinheiro;
        if (dinheiro - 1 != 0 ){
        cout << "Ainda falta " << 1 - dinheiro  << " para pagar. Porfavor insira o resto do dinheiro." << endl; 
        cin >> resto;
        }
            if (dinheiro == 1 || resto ){
            cout << "Agradecemos pela sua compra continuações de um bom dia" << endl;
            }
}
else if(produto == 03 || 3 ) {

    cout << "O seu produto custa: 1€" << endl;
    cout << "Porfavor insira o dinheiro" << endl;
    cin >> dinheiro;
        if (dinheiro - 1 != 0 ){
        cout << "Ainda falta " << 1 - dinheiro  << " para pagar. Porfavor insira o resto do dinheiro." << endl; 
        cin >> resto;
        }
            if (dinheiro == 1 || resto ){
                cout << "Agradecemos pela sua compra continuações de um bom dia" << endl;
            }


}

    return 0;
}
