#include <iostream>
using namespace std;

    struct Carro
    {
        int motor;
        char dono;
    };

    struct Marca
    {
        bool vendido;
        Carro carro;
    };


    union myunion
    {
        int x;
        char y;
        bool z;
    };

    struct Nums
    {
        int x;
        int y;
    };
    
    Nums myMatrix[4][4];
    /*
        1  2  3   4
        5  6  7   8
        9  10 11 12
        13 14 15 16
    
    */
int main(){
 


    return 0;
}