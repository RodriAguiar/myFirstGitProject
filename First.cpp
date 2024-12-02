#include <iostream>
#include <cstdlib> //permite aceder a uma biblioteca que permite gerar codigos aleatorios
#include <ctime>    //permite aceder ão tempo desde um determinada data mais especificamente 1900 mais ou menos 

using namespace std;


void tabuada () {

int x;

cout << "Coloque um falor para apresentar as suas multiplicações" << endl;

cin >> x;

for (int i=1; i<=10 ; i++) {

cout << x << " x " << i << " = " << i << endl;

}
}


void inverteNome () {

string nome;


cout << "Digite um nome" << endl;
cin >> nome;

int dimensao =nome.length ();

for (int i = dimensao-1 ; i>=0 ; i--){

cout << nome[i];

}
cout << " " << endl;
}

/**
 *Jogo adivinha letra  
 * 
 * Terás um array com as letras minúsculas do alfabeto e o computador escolherá uma letra aleatória.
 * 
 * O jogador terá que adivinhar a letra escolhida pelo computador
 * 
 * O jogador terá que digitar uma letra e o computador dirá se a letra é maior ou menor qua a letra escolhida.
 * 
 * O jogo termina quando o jogador acertar a letra escolhida
 * 
 */



int main () {

srand(time(0));
int indice = rand () % 26;
    return 0;
}