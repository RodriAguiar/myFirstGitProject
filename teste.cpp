#include <iostream>//usar sempre
using namespace std;//usar sempre proteje e ajuda o código casulo ou quarto

int main() {//main é a função principal tudo dentro das {} é um bloco de código que pertence á função main
    cout << "hello World!" << endl;




 
//adicção de números
    cout << 3 + 3 << endl;

    //subtração de números
    cout << 3 - 3 << endl;

    //Multiplicação de números
    cout << 3 * 3 << endl;

    //Divisão de números
    cout << 3 / 3 << endl;

    //Resto da divisão
    cout << 5 % 3 << endl;


//Variáveis sempre minusculas camel case, numca começar por um número
int quntLivros = 5;//int=inteiro
int x;
x = 25;
cout << quntLivros * 2 << endl;
cout << quntLivros + 5 << endl;
cout << quntLivros - 2 << endl;


bool isTrue = false;
bool isHIgh;
isHIgh = true;

float altura = 1.75;
float peso;
peso =34,6;

double altura2 = 1.75;
double peso2;
peso2 = 34.6;

char letra = 'a';
char letra2;
letra2 = 'b';

string nome = "Lucas";// string é um conjunto de chars 
string sobrenome;
sobrenome = "Santos";

    cout << " Nome " << nome << " " << sobrenome << endl;

//2 * pi * r
const double pi = 3.1416;//const=constates é um valor que é não pode variar e nem ser alterado no codigo
const int y = 2;

float valor;

cout << "idique o valor do raio";
cin >> valor;
cout << y * pi * 5 << endl;

return 0;


}