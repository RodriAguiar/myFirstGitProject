#include <iostream>
using namespace std;

//cria uma função que aceite uma struct como parâmetro e mostre on seu conteudo
//Presupostos:
//A estrutura ao ser passada na função já deve ter dados.
//A estrutura tem o seguinte formato:
//Nome:Carro
//Capos: String marca, string modelo

    struct Carro
    {
        string marca;
        string modelo;
    };

    Carro c1 = {"Toyota","AyagoX"};

    void mostrarCarro(Carro &c1)
    {
        cout << c1.marca << endl;
        cout << c1.modelo << endl;
    }

int main(){
    mostrarCarro(c1);


    return 0;
}