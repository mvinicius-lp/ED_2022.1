#include <iostream>
#include <sstream>
#include "functions.hpp"

using namespace std;

int main() {
    Banco *bank;
    
    while(true){
        string line, cmd;
        
        getline(cin, line);
        
        cout << "$" << line << "\n";
        
        stringstream ss(line);
        
        ss >> cmd;
        
        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int size;
            
            ss >> size;
            
            bank = new Banco(size);

            cout << endl;
        } else if (cmd == "show") {
            bank->show_all();

            cout << endl;
        } else if (cmd == "in") {
            string name;
            
            int docs, patience;
            
            ss >> name >> docs >> patience;
            
            bank->insere(new Cliente(name, docs, patience));

            cout << endl;
        } else if (cmd == "tic") {
            bank->passar_tempo();

            cout << endl;
        } else if (cmd == "finish") {
            while (!bank->vazio())
                bank->passar_tempo();
            
            cout << "received: " << bank->get_received() << endl;
            
            cout << "lost: " << bank->get_lost() << endl;
            
            cout << "tics: " << bank->get_tics() << endl;

            cout << endl;
        } else {
            cout << "fail: command not found\n";

            cout << endl;
        }
    }
}