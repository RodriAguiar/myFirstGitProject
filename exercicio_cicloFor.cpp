#include <iostream> //permite que nós utilizamos o cout e cin

 using namespace std;

int main () {

int numerospares [20] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 };
for (int x=0 ; x = 20; x++){
   if( numerospares [x] %2 == 0 )
    cout << numerospares [x] << endl;

//correção

 #include <iostream>
 using namesapce std;

 int numeros [20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}

 int main () {

  for (int i=0 ; i = 20; x++){
   if ( numeros [i] %2 == 0 )
    cout << numeros [i] << endl; 


  
 
}
return 0;
}
