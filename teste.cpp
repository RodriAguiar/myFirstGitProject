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
const int Y = 2;

float valor;

cout << "idique o valor do raio";
cin >> valor;
cout << Y * PI * 5 << endl;

//operadores lógicos
// ==    Igual
// !=    Diferente
// <     Maior   
// >     Menor
// >=    Maior ou igual 
// <=    Menor ou igual
// &&    e
// ||    OU
// x+=y  x é igual a x+y  


int abc; 
if( abc == 'a'){

cout << "abc é igual a a" << endl;
    }else{
        cout << "abc é diferente de a" << endl;

    }


int ( x == 1);
int ( Y == 2);

if (Y == 2 ) {
    cout << "v igual a dois" << endl;
}else if(Y == 3){
    cout << "y é igual a três" << endl;
}else if(Y  == 4){
    cout << "y é igual a quatro" << endl;

}else{
    cout << "nenhum dos valores é igual a 2, 3 ou 4" << endl;

}


//if comparar valores
//else if vai ser chamada se a anterior for falsa
//switch é para selecionar um dos blocos de comando
//while loop
// do while executa pelo menos uma vez oque está no bloco de comando
//loop for nessesário três parametros
//brake para qualquer ciclo seja while loop do while
//continue continua para o começo do loop
//array espécie de armário para guaradar informações int variável[número de "gavetas"] ou string nomeDosAlunos[] = {"João" , "Maria" , "Jose"};
//struct criar um novo tipo de variavel
//enums 

/*
Array de Inteiros com 20 elementos 
ciclo for para mostrar apenas elementos pares
*/



return 0;
}
