#include <iostream>
#include <fstream>
#include "./util.h"
#include "./Huffman.h"
#include "./Arithmetic.h"

using namespace std;

int main(){
    // for txt
    ifstream ifs("./test_case.txt");
    string content( 
        (istreambuf_iterator<char>(ifs)),
        (istreambuf_iterator<char>()) 
    );

    Map dictionary = get_dictionary_txt(content);

    // Todo for binary file

    // encode here
    // Huffman huffman;
    Arithmetic arithmetic;
    string encode = arithmetic.encode(content, dictionary);
    // string decode = arithmetic.decode(encode, dictionary);
}