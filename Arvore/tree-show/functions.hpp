//funções
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

struct BTree {
    Node* root {nullptr};

    BTree() {}

    BTree(string &serial) {      
        stringstream ss(serial);
        
        this->root = extract_serial(ss);
    }

    Node* extract_serial(stringstream &ss) {
        string element {};
        ss >> element;

        if (element == "#") {
            return nullptr;
        }
        
        int value = stoi(element);
        
        Node* node = new Node(value);

        node->left = extract_serial(ss);
        node->right = extract_serial(ss); 
        
        return node;
    }

    ~BTree() {
        __Destruir(this->root);
    }

    void __Destruir(Node* node) {
        if (node == nullptr) {
            return;
        }

        __Destruir(node->left);
        __Destruir(node->right);

        delete node;
    }

    void show() {
        __show(this->root);
    }

    void __show(Node* node, int level = 0) {
        if (node == nullptr) {
            cout << string(level * 4, '.')  << "#" << endl;
            return;
        }

        if (node->left != nullptr || node->right != nullptr) {
            __show(node->left, level + 1);

            cout << string(level * 4, '.') << node->value << endl;

            __show(node->right, level + 1);

            return;
        } 
        
        cout << string(level * 4, '.') << node->value << endl;
    }
};