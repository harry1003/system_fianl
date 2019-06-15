#include <fstream>
#include <limits>
#include <bitset>
#include "util.h"


// Warning: some special words can't not show correctly
Map get_dictionary_txt(string content){
    Map dictionary;
    for(size_t i=0; i<content.size(); i++){
        string s(1, content[i]); 
        Map::iterator it = dictionary.find(s);
        if(it == dictionary.end()){
            dictionary.insert(make_pair(s, 1));
        }
        else{
            it->second++;
        }
    }
    dictionary.insert(make_pair("EOF", 1));
    Map::iterator it = dictionary.begin();
    for(; it != dictionary.end(); it++){
        it->second /= (content.size() + 1);
    }
    return dictionary;
}


// http://www.cplusplus.com/forum/beginner/231403/
string read_bits(string filename){
    using byte = unsigned char;
    constexpr size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits;
    using bits = std::bitset<BITS_PER_BYTE>;

    if(ifstream file{filename, ios::binary}){
        string result;
        file >> noskipws;
        byte b;
        while(file >> b)
            result += bits(b).to_string();
        return result ;
    }
    else return {};
}
