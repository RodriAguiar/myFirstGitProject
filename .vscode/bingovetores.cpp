#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

vector<int> nums;

class cartoes{
    private:
        bool jasaiu;
        int num;
        vector<vector<int>> table;

    public:
        //constructor
        cartoes(bool out, int num){
            jasaiu = out;
            num = num;
        } 
};

int main(){

    return 0;
}