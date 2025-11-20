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

void menu(){

cout << "\n\n" << endl;    
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

cout << RED << "   █     █░ ▄▄▄       ██▀███    ██████ " << endl;
cout <<        "  ▓█░ █ ░█░▒████▄    ▓██ ▒ ██▒▒██    ▒ " << endl;
cout <<        "  ▒█░ █ ░█ ▒██  ▀█▄  ▓██ ░▄█ ▒░ ▓██▄   " << endl;
cout <<        "  ░█░ █ ░█ ░██▄▄▄▄██ ▒██▀▀█▄    ▒   ██▒" << endl;
cout <<        "  ░░██▒██▓  ▓█   ▓██▒░██▓ ▒██▒▒██████▒▒" << endl;
cout <<        "  ░ ▓░▒ ▒   ▒▒   ▓▒█░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░" << endl;
cout <<        "    ▒ ░ ░    ▒   ▒▒ ░  ░▒ ░ ▒░░ ░▒  ░ ░" << endl;
cout <<        "    ░   ░    ░   ▒     ░░   ░ ░  ░  ░  " << endl;
cout <<        "      ░          ░  ░   ░           ░  " << endl;
cout <<        "                                       " << endl;
cout << RESET << endl;
cout << "\n\n" << endl;

}


int main(){
    system("clear");

    menu();

    

    return 0;
}