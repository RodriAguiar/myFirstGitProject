#include <iostream>
using namespace std;

struct Tipo
{
    float classificacao;
    string tipo;
    string caracteristicas;
};

struct Jogo
{
    string nome;
    int codigo;
    Tipo tipo;
};

Jogo jogo1 = {"Genshin Impact",18595,{4.5,"RPG","Mundo Aberto"}};

int main(){


//cout << "Digite o seu nome abaixo: " << endl;
//cin >> aluno1.nome;

//cout << "Digite a sua idade: " << endl;
//cin >> aluno1.idade;

//cout << "Digite as suas caracteristicas" << endl;
//cin >> aluno1.caracteristicas;

//cout << "Digite o nome da sua escola: " << endl;
//cin >> aluno1.escola.nome;

//cout << "Digite a morada da escola: " << endl;
//cin >> aluno1.escola.morada;

//system("clear");

//cout << aluno1.nome << endl;

system("clear");     
cout << "                 |Steam|" << endl;
cout << "+--------------------------------------+" << endl;
cout << "|Nome do Jogo: " << jogo1.nome << "          |" << endl;
cout << "|Código do Jogo: " << jogo1.codigo << "                 |" << endl;
cout << "|Características do Jogo: " << jogo1.tipo.caracteristicas << " |"<< endl;
cout << "|Classificação do Jogo: " << jogo1.tipo.classificacao << "            |" << endl;
cout << "|Tipo do Jogo: " << jogo1.tipo.tipo << "                     |" << endl;
cout << "+--------------------------------------+" << endl;

    return 0;
}