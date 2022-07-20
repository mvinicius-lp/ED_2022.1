#include <iostream>
#include <sstream>
#include "functions.hpp"

using namespace std;

int main() {
    List ll;

    while(true) {
        string line, cmd;
        int value;

        getline(cin, line);

        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        } else if(cmd == "show") {
            cout << ll << endl;
        } else if(cmd == "push_back") {
            while(ss >> value)
                ll.push_back(value);
        } else if(cmd == "push_front") {
            while(ss >> value)
                ll.push_front(value);
        } else if(cmd == "pop_back") {
            ll.pop_back();
        } else if(cmd == "pop_front") {
            ll.pop_front();
        } else if(cmd == "size") {
            cout << ll.size() << endl;
        }
    }

    return 0;
}