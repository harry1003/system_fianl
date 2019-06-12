#include <iostream>
#include <fstream>
#include "./util.h"
#include "./Huffman.h"

using namespace std;

int main(){
    ifstream ifs("./test_case.txt");
    string content( 
        (istreambuf_iterator<char>(ifs)),
        (istreambuf_iterator<char>()) 
    );

    Map dictionary = get_dictionary(content);
    Huffman huffman;
    huffman.encode(content, dictionary);
}