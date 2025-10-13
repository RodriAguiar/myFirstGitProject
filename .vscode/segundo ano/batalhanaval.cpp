#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"


    struct Nums
    {
        bool boat;        
        bool shot;
    };

        Nums myMatrixA[10][10];
        Nums myMatrixB[10][10];

    string estado(Nums x)

    {
        if (x.boat == 1 && x.shot == 1)
        {
            return "\033[31m X\033[37m";
        }

        if (x.boat == 1 && x.shot == 0 )
        {
            return "\033[90m[]\033[37m" ;
        }

        if (x.boat == 0 && x.shot == 1 )
        {
            return "\033[96m x \033[37m";
        }
        return "\033[96m ~\033[37m";
    }
    
    string linhaEstado(Nums matrix[10][10], int y)
    {
        string linha = "";
        linha += estado(matrix[1][y]);
        linha += estado(matrix[2][y]);
        linha += estado(matrix[3][y]);
        linha += estado(matrix[4][y]);
        linha += estado(matrix[5][y]);
        linha += estado(matrix[6][y]);
        linha += estado(matrix[7][y]);
        linha += estado(matrix[8][y]);
        linha += estado(matrix[9][y]);
        linha += estado(matrix[10][y]);
        return linha;
    }

    void table()
    {
            system("clear");

            cout << RED <<"    A B C D E F G H I J" << endl;
            cout << WHITE << "  +--------------------+" << endl;
            cout << BLUE <<" 1\033[37m|" << WHITE << linhaEstado(myMatrixA,1) << endl
            << BLUE <<" 2\033[37m|" << WHITE <<  linhaEstado(myMatrixA,2) << endl
            << BLUE <<" 3\033[37m|" << WHITE <<  linhaEstado(myMatrixA,3) << endl
            << BLUE <<" 4\033[37m|" << WHITE <<  linhaEstado(myMatrixA,4) << endl
            << BLUE <<" 5\033[37m|" << WHITE <<  linhaEstado(myMatrixA,5) << endl
            << BLUE <<" 6\033[37m|" << WHITE <<  linhaEstado(myMatrixA,6) << endl
            << BLUE <<" 7\033[37m|" << WHITE <<  linhaEstado(myMatrixA,7) << endl
            << BLUE <<" 8\033[37m|" << WHITE <<  linhaEstado(myMatrixA,8) << endl
            << BLUE <<" 9\033[37m|" << WHITE <<  linhaEstado(myMatrixA,9) << endl
            << BLUE <<"10\033[37m|" << WHITE <<  linhaEstado(myMatrixA,10) << endl;
            cout << "  +--------------------+" << endl;
            cout << "         PLAYER 2" << endl;

        cout << "  ______________________\n" << endl;

            cout << RED <<"    A B C D E F G H I J" << endl;
            cout << WHITE << "  +--------------------+" << endl;
            cout << BLUE <<" 1\033[37m|" << WHITE << linhaEstado(myMatrixB,1) << endl
            << BLUE <<" 2\033[37m|" << WHITE <<  linhaEstado(myMatrixB,2) << endl
            << BLUE <<" 3\033[37m|" << WHITE <<  linhaEstado(myMatrixB,3) << endl
            << BLUE <<" 4\033[37m|" << WHITE <<  linhaEstado(myMatrixB,4) << endl
            << BLUE <<" 5\033[37m|" << WHITE <<  linhaEstado(myMatrixB,5) << endl
            << BLUE <<" 6\033[37m|" << WHITE <<  linhaEstado(myMatrixB,6) << endl
            << BLUE <<" 7\033[37m|" << WHITE <<  linhaEstado(myMatrixB,7) << endl
            << BLUE <<" 8\033[37m|" << WHITE <<  linhaEstado(myMatrixB,8) << endl
            << BLUE <<" 9\033[37m|" << WHITE <<  linhaEstado(myMatrixB,9) << endl
            << BLUE <<"10\033[37m|" << WHITE <<  linhaEstado(myMatrixB,10) << endl;
            cout << "  +--------------------+" << endl; 
            cout << "         PLAYER 1" << endl;
    }

    void playerAct(){
        int digito;
        char letra;
        int letraNum;

        cin >> digito,letra;
    
        if (letra = 'a' || 'A')
        {
            letraNum == 1;
        }

        if (letra = 'b' || 'B'){

           letraNum == 2;
        };

        if (letra = 'c' || 'C'){

            letraNum == 3;
         };

        if (letra = 'd' || 'D'){

            letraNum == 4;
         };
 
        if (letra = 'e' || 'E'){
 
             letraNum == 5;
          };

        if (letra = 'f' || 'F')
          {
              letraNum == 6;
          }
  
        if (letra = 'g' || 'G'){
  
             letraNum == 7;
          };
  
        if (letra = 'h' || 'H'){
  
              letraNum == 8;
           };
  
        if (letra = 'i' || 'I'){
  
              letraNum == 9;
           };
   
        if (letra = 'j' || 'J'){
   
               letraNum == 10;
            };

        if (digito,letraNum > 10 || digito,letraNum < 1){

            cout << "Este digito é invalido" << endl;
        };


        

    };

int main(){



    table();
    playerAct();


    return 0;
}