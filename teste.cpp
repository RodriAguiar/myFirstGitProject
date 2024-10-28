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
const double PI = 3.1416;//const=constates é um valor que é não pode variar e nem ser alterado no codigo e são sempre maiusculas
const int y = 2;

float valor;

cout << "idique o valor do raio";
cin >> valor;
cout << y * PI * 5 << endl;

//operadores lógicos
// ==    Igual
// !=    Diferente
// <     Maior   
// >     Menor
// >=    Maior ou igual 
// <=    Menor ou igual
// &&    e
// ||    OU



int abc; 
if( abc == 'a'){

cout << "abc é igual a a" << endl;
    }else{
        cout << "abc é diferente de a" << endl;

    }


int ( x == 1);
int ( y == 2);

if (y == 2 ) {
    cout << "v igual a dois" << endl;
}else if(y == 3){
    cout << "y é igual a três" << endl;
}else if(y  == 4){
    cout << "y é igual a quatro" << endl;

}else{
    cout << "nenhum dos valores é igual a 2, 3 ou 4" << endl;

}


//if comparar valores
//else if vai ser chamada se a anterior for chamada
//switch é para selecionar um dos blocos de comando
//




return 0;
}
