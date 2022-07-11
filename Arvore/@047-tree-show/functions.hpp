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

    void __show(Node* node, int level = 0) {
        if (node == nullptr) {
            std::cout << std::string(level * 4, '.')  << "#" << std::endl;
            return;
        }

        if (node->left != nullptr || node->right != nullptr) {
            __show(node->left, level + 1);

            std::cout << std::string(level * 4, '.') << node->value << std::endl;

            __show(node->right, level + 1);

            return;
        } 
        
        std::cout << std::string(level * 4, '.') << node->value << std::endl;
    }
};