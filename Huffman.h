#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Huffman{
public:
    Huffman(){};
    string encode(unordered_map<string, double> dictionary);
    string decode(string binary_string);
};