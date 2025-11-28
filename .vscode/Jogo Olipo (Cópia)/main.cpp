#include <iostream>
#include <ctime>

using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BGGRAY "\033[100m"
#define PURPLE "\e[0;35m"

/*struct Weapon{
    
    string name;
    bool atk = 0; 


};*/

struct Stats{
    
    int basedmg;
    int basehp;
    string category;

};

class cards{
    private:
        int    rarity;
        string name;
        string element;
//      Weapon weapon;
        string goodvs;
        Stats  stats;
    public:    
    
    void character(int rarity,string name, string elment, string goodvs){
        rarity = rarity;
        name = name;
        element = element;
        goodvs = goodvs;
    }

};

void character(){



};


void menu(){

cout << "\n\n" << endl;

cout << " ▄██████▄   ▄█        ▄█    ▄▄▄▄███▄▄▄▄      ▄███████▄ ███    █▄     ▄████████ " << endl;
cout << "███    ███ ███       ███  ▄██▀▀▀███▀▀▀██▄   ███    ███ ███    ███   ███    ███ " << endl;
cout << "███    ███ ███       ███▌ ███   ███   ███   ███    ███ ███    ███   ███    █▀  " << endl;
cout << "███    ███ ███       ███▌ ███   ███   ███   ███    ███ ███    ███   ███        " << endl;
cout << "███    ███ ███       ███▌ ███   ███   ███ ▀█████████▀  ███    ███ ▀███████████ " << endl;
cout << "███    ███ ███       ███  ███   ███   ███   ███        ███    ███          ███ " << endl;
cout << "███    ███ ███▌    ▄ ███  ███   ███   ███   ███        ███    ███    ▄█    ███ " << endl;
cout << " ▀██████▀  █████▄▄██ █▀    ▀█   ███   █▀   ▄████▀      ████████▀   ▄████████▀  " << endl;
cout << "" << endl;

cout << "\n\n";

cout << "  ░██████   ░██ ░██ ░██           ░██            " << endl;
cout << " ░██   ░██  ░██ ░██                              " << endl;
cout << "░██     ░██ ░██ ░██ ░██░████████  ░██ ░███████   " << endl;
cout << "░██     ░██ ░██ ░██ ░██░██    ░██ ░██░██    ░██  " << endl;
cout << "░██     ░██ ░██ ░██ ░██░██    ░██ ░██░██         " << endl;
cout << " ░██   ░██  ░██ ░██ ░██░███   ░██ ░██░██    ░██  " << endl;
cout << "  ░██████   ░██ ░██ ░██░██░█████  ░██ ░███████   " << endl;
cout << "                       ░██                       " << endl;
cout << "                       ░██                       " << endl;
cout << "\n" << endl;

cout << PURPLE << "▓█████▄ ▓█████ ██▒   █▓ ▒█████   █    ██  ██▀███ " << endl;
cout <<           "▒██▀ ██▌▓█   ▀▓██░   █▒▒██▒  ██▒ ██  ▓██▒▓██ ▒ ██▒" << endl;
cout <<           "░██   █▌▒███   ▓██  █▒░▒██░  ██▒▓██  ▒██░▓██ ░▄█ ▒" << endl;
cout <<           "░▓█▄   ▌▒▓█  ▄  ▒██ █░░▒██   ██░▓▓█  ░██░▒██▀▀█▄  " << endl;
cout <<           "░▒████▓ ░▒████▒  ▒▀█░  ░ ████▓▒░▒▒█████▓ ░██▓ ▒██▒" << endl;
cout <<           " ▒▒▓  ▒ ░░ ▒░ ░  ░ ▐░  ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ░ ▒▓ ░▒▓░" << endl;
cout <<           " ░ ▒  ▒  ░ ░  ░  ░ ░░    ░ ▒ ▒░ ░░▒░ ░ ░   ░▒ ░ ▒░" << endl;
cout <<           " ░ ░  ░    ░       ░░  ░ ░ ░ ▒   ░░░ ░ ░   ░░   ░ " << endl;
cout <<           "   ░       ░  ░     ░      ░ ░     ░        ░     " << endl;
cout <<           "░                 ░                              " << endl;
cout << RESET << endl;
cout << "\n\n" << endl;

}



int main(){
    system("clear");

    menu();

    

    return 0;
}