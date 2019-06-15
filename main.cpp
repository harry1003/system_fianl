#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

#include "./util.h"
#include "./Huffman.h"
#include "./Arithmetic.h"
#include "./LZW.h"

using namespace std;

int main(){
    string mode = "img";
    string file_name = "test_case_1";

    string content = "";
    if(mode == "txt"){
        ifstream ifs(file_name);
        string txt( 
            (istreambuf_iterator<char>(ifs)),
            (istreambuf_iterator<char>()) 
        );
        content = txt;
    }
    else if(mode == "binary"){
        content = read_bits(file_name);
    }
    else if(mode == "img"){
        ifstream ifs("test_case_img.txt");
        ifs >> content;
    }

    double DICS, DICE;
    DICS = clock();
    Map dictionary = get_dictionary_txt(content);
    DICE = clock();

    // result
    double origin_size = content.size() * ceil(log2(dictionary.size()));
    cout << dictionary.size() << endl;
    cout << ceil(log2(dictionary.size())) << endl;
    double HES, HEE, HDE;
    HES = clock();
    Huffman huffman;
    string encode_h = huffman.encode(content, dictionary);
    HEE = clock();
    string decode = huffman.decode(encode_h, dictionary);
    HDE = clock();

    double AES, AEE, ADE;
    AES = clock();
    Arithmetic arithmetic;
    string encode_a = arithmetic.encode(content, dictionary);
    AEE = clock();
    string decode_a = arithmetic.decode(encode_a, dictionary);
    ADE = clock();

    LZW lzw;
    double LES, LEE, LDE;
    LES = clock();
    vector<string> encode_l = lzw.encode(content);
    LEE = clock();
    string decode_l = lzw.decode(encode_l);
    LDE = clock();
    
    cout << endl;

    double compress_size_h = encode_h.size();
    cout << "=====================" << endl;
    cout << "Get dictionary:          " << (DICE - DICS) / CLOCKS_PER_SEC << " s" << endl;
    cout << "=====================" << endl;
    cout << "Huffman encoding:        " << (HEE - HES) / CLOCKS_PER_SEC << " s" << endl;
    cout << "Huffman decoding:        " << (HDE - HEE) / CLOCKS_PER_SEC << " s" << endl;
    cout << "Original size:           " << origin_size << endl;
    cout << "Huffman encode size:     " << compress_size_h << endl;
    cout << "Compression rate:        " << (origin_size - compress_size_h) / origin_size << endl;
    cout << endl;

    double compress_size_a = encode_a.size();
    cout << "=====================" << endl;
    cout << "Arithmetic encoding:     " << (AEE - AES) / CLOCKS_PER_SEC << " s" << endl;
    cout << "Arithmetic decoding:     " << (ADE - AEE) / CLOCKS_PER_SEC << " s" << endl;
    cout << "Original size:           " << origin_size << endl;
    cout << "Arithmetic encode size:  " << compress_size_a << endl;
    cout << "Compression rate:        " << (origin_size - compress_size_a) / origin_size << endl;
    cout << endl;

    double compress_size_l = encode_l.size() * ceil(log2(lzw.dictionary_size));
    cout << "=====================" << endl;
    cout << "LZW encoding:            " << (LEE - LES) / CLOCKS_PER_SEC << " s" << endl;
    cout << "LZW decoding:            " << (LDE - LEE) / CLOCKS_PER_SEC << " s" << endl;
    cout << "Original size:           " << origin_size << endl;
    cout << "LZW encode size:         " << compress_size_l << endl;
    cout << "Compression rate:        " << (origin_size - compress_size_l) / origin_size << endl;
    cout << endl;
}