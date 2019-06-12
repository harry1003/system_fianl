#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"
using namespace std;

class Huffman{
public:
    Huffman(){};
    string encode(string content, Map dictionary);
    string decode(string binary_string);
};