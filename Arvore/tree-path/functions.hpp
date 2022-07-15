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

    BTree() {};

    BTree(std::string &serial) {
        std::stringstream ss(serial);

        root = extract_serial(ss);
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
        std::string element{};
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

    std::string find_path(int value) {
        return _find_path(root, value);
    }

    std::string _find_path(Node* node, int value) {
        if (node == nullptr) {
            return "";
        } else if (node->value == value) {
            return "x";
        }

        auto sonsL = _find_path(node->left, value);
        
        if (sonsL != "" && sonsL != "!") {
            return "l" + sonsL;
        }

        auto sonsR = _find_path(node->right, value);
        
        if (sonsR != "" && sonsR != "!") {
            return "r" + sonsR;
        }
        
        return "!";
    }
};