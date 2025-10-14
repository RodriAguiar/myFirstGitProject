#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

int cordX,cordY;



    struct Nums
    {
        bool boat;        
        bool shot;
    };

    struct Boat
    {
        string nome;
        int tamanho;
        Nums nums;
    };

    Boat AircraftCarrier = {"AircraftCarrier",5,{0,0}};
    Boat Battleship ={"Battleship",4,{0,0}};
    Boat Cruiser = {"Cruiser",3,{0,0}};
    Boat Submarine = {"Submarine",3,{0,0}};
    Boat Destroyer = {"Submarine",2,{0,0}};

        Nums myMatrixA[10][10];
        Nums myMatrixB[10][10];

    string estado(Nums x)

    {
        if (x.boat == 1 && x.shot == 1)
        {
            return "\033[31m [X]\033[37m";
        }

        if (x.boat == 1 && x.shot == 0 )
        {
            return "\033[40m[]\033[37m" ;
        }

        if (x.boat == 0 && x.shot == 1 )
        {
            return "\033[96mW \033[47m";
        }
        return "\033[46m ~\e[0m";
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

            cout << RED <<"   1 2 3 4 5 6 7 8 9 10" << endl;
            cout << WHITE << "  +--------------------+" << endl;
            cout << BLUE <<" A\033[37m|" << WHITE << linhaEstado(myMatrixA,1) << endl
            << BLUE <<" B\033[37m|" << WHITE <<  linhaEstado(myMatrixA,2) << endl
            << BLUE <<" C\033[37m|" << WHITE <<  linhaEstado(myMatrixA,3) << endl
            << BLUE <<" D\033[37m|" << WHITE <<  linhaEstado(myMatrixA,4) << endl
            << BLUE <<" E\033[37m|" << WHITE <<  linhaEstado(myMatrixA,5) << endl
            << BLUE <<" F\033[37m|" << WHITE <<  linhaEstado(myMatrixA,6) << endl
            << BLUE <<" G\033[37m|" << WHITE <<  linhaEstado(myMatrixA,7) << endl
            << BLUE <<" H\033[37m|" << WHITE <<  linhaEstado(myMatrixA,8) << endl
            << BLUE <<" I\033[37m|" << WHITE <<  linhaEstado(myMatrixA,9) << endl
            << BLUE <<" J\033[37m|" << WHITE <<  linhaEstado(myMatrixA,10) << endl;
            cout << "  +--------------------+" << endl;
            cout << "         PLAYER 2" << endl;

        cout << "  ______________________\n" << endl;

            cout << RED <<"   1 2 3 4 5 6 7 8 9 10" << endl;
            cout << WHITE << "  +--------------------+" << endl;
            cout << BLUE <<" A\033[37m|" << WHITE << linhaEstado(myMatrixB,1) << endl
            << BLUE <<" B\033[37m|" << WHITE <<  linhaEstado(myMatrixB,2) << endl
            << BLUE <<" C\033[37m|" << WHITE <<  linhaEstado(myMatrixB,3) << endl
            << BLUE <<" D\033[37m|" << WHITE <<  linhaEstado(myMatrixB,4) << endl
            << BLUE <<" E\033[37m|" << WHITE <<  linhaEstado(myMatrixB,5) << endl
            << BLUE <<" F\033[37m|" << WHITE <<  linhaEstado(myMatrixB,6) << endl
            << BLUE <<" G\033[37m|" << WHITE <<  linhaEstado(myMatrixB,7) << endl
            << BLUE <<" H\033[37m|" << WHITE <<  linhaEstado(myMatrixB,8) << endl
            << BLUE <<" I\033[37m|" << WHITE <<  linhaEstado(myMatrixB,9) << endl
            << BLUE <<" J\033[37m|" << WHITE <<  linhaEstado(myMatrixB,10) << endl;
            cout << "  +--------------------+" << endl; 
            cout << "         PLAYER 1" << endl;
            
            cout << "Choose your ship and place it: " << endl;
            cout << "+-------------------------------------------+\n" << "|R - To rotate|[Enter] To choose other ship |" << endl;
            cout << "+-------------------------------------------+" <<endl;


    }

    void playerAct(int& cordX, int& cordY){
    
        string input;

        cout << "You: ";
        cin >> input;
    
        if (input[0] == 'A' || input[0] = 'a')
        {
            cordY == 0;
        }

        else if (input[0] == 'b' || input[0] 'B')
        {
            cordY == 1;
        }

        if (input[0] == 'c' || 'C'){

            cordY == 2;
         };

        if (input[0] = 'd' || 'D'){

            cordY == 3;
         };
 
        if (letra = 'e' || 'E'){
 
             letraNum == 4;
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
    myMatrixA[1][1].boat = 0;
    myMatrixA[1][1].shot = 1;


    table();


    playerAct(a,b);

    return 0;
}
