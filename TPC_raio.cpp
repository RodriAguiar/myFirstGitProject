#include <iostream>
using namespace std;
const float PI=3.14159;
float raio;

int main() {
    cout << "Idique o valor do raio" << endl;
cin >> raio;

cout << "O perimetro da circunferência  é: "<< endl;
cout << 2*PI*raio << endl;

cout << "A área da circunferência é: " << endl;
cout << PI*(raio*raio)<< endl;

cout << "O diânmetro é: " << endl;
cout << 2*raio << endl;

    return 0;
}
