#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"
using namespace std;

class Node{
public:
	double p;
    Node * left;
    Node * right;
    string data;
};

class Huffman{
public:
    Huffman(){};
    string encode(string content, Map dictionary);
    string decode(string binary, Map dictionary);

private:
    void buildMap(Map& dictionary);
    Node* buildTree(Map& dictionary);
    void set_data(unordered_map<string, string>& symbol_map, Node* root, string binary);
    Node* createNode(string data, double p, Node* left, Node* right);
    
    unordered_map<string, string> symbol_map;
    Node* root;
};

class CompareNode{
public:
    bool operator()(const Node* node1, const Node* node2) const
    {
        return node1->p > node2->p;
    }
};