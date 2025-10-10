#include <iostream>
#include <string>
using namespace std;

//Jogo da forca simplificado e com frase e conforme as pessoas vao acertando os espaços a letras vão se revelando.

struct letrasall{
char letra;
bool acerto;

};

int main() {

system ("clear");

string frase;


cout << "\t\t" << "Bem-vindo ao jogo" << "\t\t" << endl;
cout << "\t" <<"O jogador 1 terá que selecionar uma frase." << endl;
cout << "\n" << "\t" << "Jogador 1 coloca a frase a abaixo: " << endl;

getline(cin, frase);
 
system ("clear");

for (char l : frase){ 
    
    l != ' ' ? cout << "_ " : cout << "  " ;

}
cout << "\n";



    return 0;
}
