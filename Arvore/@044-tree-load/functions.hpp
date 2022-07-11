#pragma once

#include <iostream>
#include <sstream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

struct BTree {
    Node* root {nullptr};

    BTree() {}

    BTree(std::string &serial) {      
        std::stringstream ss(serial);
        
        this->root = extract_serial(ss);
    }

    ~BTree() {
        __destroy(this->root);
    }

    void __destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        __destroy(node->left);
        __destroy(node->right);

        delete node;
    }

    Node* extract_serial(std::stringstream &ss) {
        std::string element {};
        ss >> element;

        if (element == "#") {
            return nullptr;
        }
        
        int value = std::stoi(element);
        
        Node* node = new Node(value);

        node->left = extract_serial(ss);
        node->right = extract_serial(ss); 
        
        return node;
    }

    ~BTree() {
        __destroy(this->root);
    }

    void __destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        __destroy(node->left);
        __destroy(node->right);

        delete node;
    }

    void show() {
        __show(this->root);
    }

    void __show(Node* node, std::string heranca = "") {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr)) {
            __show(node->left, heranca + "l");
        } 

        for (int index = 0; index < (int) heranca.size() - 1; index++) {
            std::cout << (heranca[index] != heranca[index + 1] ? "│   " : "    ");
        }

        if (heranca != "") {
            std::cout << (heranca.back() == 'l' ? "┌───" : "└───");
        }

        if (node == nullptr) {
            std::cout << "#" << std::endl;
            return;
        }

        std::cout << node->value << std::endl;

        if (node != nullptr && (node->left != nullptr || node->right != nullptr)) {
            __show(node->right, heranca + "r");
        }
    }

    void show_in_order() {
        std::cout << "[ ";
        
        __show_in_order(root);

        std::cout << "]\n";
    }

    void __show_in_order(Node * node) {
        if(node == nullptr) {
            return;
        }

        __show_in_order(node->left);

        std::cout << node->value << " ";

        __show_in_order(node->right);
    }
};