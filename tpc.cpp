#include <iostream>
using namespace std;

float horas;
float salario;
float descontoIRS;
float IRS = 0.125;

int main() {
   
    cout << "Quantas horas trabalhaste?" << endl;
    cin >> horas;

    cout << "Quanto ganhas por hora?" << endl;
    cin >> salario;

    float total = horas * salario;
    descontoIRS = total * IRS;
    float totalComDesconto = total - descontoIRS;

    cout << "Vais receber:" << endl;
    cout << total << " Euros" << endl;

    cout << "Com o desconto do IRS vais receber:" << endl;
    cout << totalComDesconto << " Euros" << endl;

    return 0;
}
