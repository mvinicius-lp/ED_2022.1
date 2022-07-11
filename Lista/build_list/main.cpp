#include <iostream>
#include <sstream>
#include "functions.hpp"


int main() {
    List ll;

    while(true) {
        std::string line, cmd;
        int value;

        getline(std::cin, line);

        std::cout << "$" << line << std::endl;

        std::stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        } else if(cmd == "show") {
            std::cout << ll << std::endl;
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
            std::cout << ll.size() << std::endl;
        }
    }

    return 0;
}