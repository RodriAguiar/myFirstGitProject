#include <iostream>
using namespace std;

int numeros[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15, 16, 17, 
                    18, 19, 20};
int main () {

for(int x = 0; x < 20; x++){
    if( numeros [x] %2==0 ) {
    cout << numeros [x] << endl;
    }
}

int myArr [20];
myArr[8] = 9;
 

return 0;
}