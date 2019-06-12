#include "./Huffman.h"

string Huffman::encode(unordered_map<string, double> dictionary){
    string input = "10000111";
    unordered_map<string, double> d;
    d.insert(make_pair("00", 0.11));
    d.insert(make_pair("01", 0.25));
    d.insert(make_pair("10", 0.25));
    d.insert(make_pair("11", 0.25));

    cout << d.find("00")->second << endl;
    return "fff";
}

string Huffman::decode(string binary_file){

}