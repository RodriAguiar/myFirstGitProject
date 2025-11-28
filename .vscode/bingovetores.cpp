#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BGGRAY "\033[100m"
#define PURPLE "\e[0;35m"


class cards{
    private:

        struct Card{
            int number;
            char letter;
        }; 

    public:

        cards(Card card){
            vector<int> nums;            
            bool unique;        
            
            do{
                for (int i = 0; i <= 5; i++)
                {
                    
                }
                



                }while(!unique);


            

        }
};

int main(){

    return 0;
}