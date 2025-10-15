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
    
        if (input[0] == 'a' || input[0] == 'A')
        {
            cordY == 0;
        }

        else if (input[0] == 'b' || input[0] == 'B')
        {
            cordY == 1;
        }

        else if(input[0] == 'c' || input[0] =='C'){

            cordY == 2;
         }

         else if(input[0] = 'd' || input[0] =='D'){

            cordY == 3;
         }
 
         else if ( input[0] == 'e' || input[0] =='E'){
 
            cordY== 4;
          }

          else if(input[0] ==  'f' || input[0] == 'F')
          {
            cordY == 6;
          }
  
          else if(input[0] == 'g' || input[0] == 'G'){
  
            cordY== 7;
          }
  
          else if (input[0] == 'h' ||input[0] ==  'H'){
  
            cordY == 8;
           }
  
           else if(input[0] ==  'i' ||input[0] ==  'I'){
  
            cordY == 9;
           }
   
           else if(input[0] == 'j' || input[0] == 'J'){
   
            cordY == 10;
            }

        else if (cordX,cordY > 10 || cordX,cordY < 1){

            cout << "Este digito é invalido" << endl;
        };

        switch (size(input))
        {
            case 2:

            if (input[1]== '1')
            {
                cordX = 0;
            }
            else if (input[1]== '2')
            {
                cordX = 1;
            }
            else if (input[1]== '3')
            {
                cordX = 2;
            }
            else if (input[1]== '4')
            {
                cordX = 3;
            }
            else if (input[1]== '5')
            {
                cordX = 4;
            }
            else if (input[1]== '6')
            {
                cordX = 5;
            }
            else if (input[1]== '7')
            {
                cordX = 6;
            }
            else if (input[1]== '8')
            {
                cordX = 7;
            }
            else if (input[1]== '9')
            {
                cordX = 8;
            }
            else{
                cordX = -1;
            }
            break;
        
            case 3:

            if(input[1] == '1' && input[2] == '0'){
                cordX = 9;
            }else{

                cordX = -1;
            }
            break;

            default:
            cordX = -1; 
            cordY = -1;
                break;
            }
    };

    void shotact(int& cordX, int& cordY){

        if (myMatrixA[cordY][cordX].boat == 1 ){

            myMatrixA[cordY][cordX].shot == 1;
        }
        else {
            myMatrixA[cordY][cordX].shot == 1;
        }
         
        if (myMatrixB[cordY][cordX].boat == 1 ){

            myMatrixB[cordY][cordX].shot == 1;
        }
        else {
            myMatrixB[cordY][cordX].shot == 1;
        }

    }

    void boatact(int& cordX,int& cordY){
        


    };

int main(){

    int life = 10;

    while (life == 0)
    {
    
        table();
    
        int x, y;
        myMatrixB[1][1].boat = 1;
        playerAct(x, y);
        myMatrixB[cordY][cordX].boat = 1;
        life --;
    };
    return 0;
}
