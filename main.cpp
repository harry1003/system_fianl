#include <iostream>
#include "./Huffman.h"

using namespace std;

int main(){
    cout << "test" << endl;
    Huffman huffman;
    unordered_map<string, double> dictionary;
    huffman.encode(dictionary);
}