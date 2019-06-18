#include "./Arithmetic.h"
int temp = 0;

string Arithmetic::encode(string content, Map dictionary){
    temp = content.size();
    cout << "Arithmetic encoding" << endl;
    Map::iterator it = dictionary.begin();
    double accumulate = 0;
    for(; it != dictionary.end(); it++){
        double size = it->second;
        it->second = accumulate;
        accumulate = accumulate + size;
    }

    cout << "start encoding" << endl;
    Range range;
    string s = "";
    string answer = "";
    for(size_t i=0; i<content.size(); i++){
        string symbol(1, content[i]);
        it = dictionary.find(symbol);
        double low = it->second;
        double high = 0;
        if(++it == dictionary.end()){
            high = 1;
        }
        else{
            high = it->second;
        }
        
        s = range.encode_symbol(low, high);
        answer += s;

        if(i % 100000 == 0){
            cout << "encoding: " << i << " / " << content.size() << endl;
        }
    }
    it = dictionary.find("EOF");
    double low = dictionary.find("EOF")->second;
    double high = 0;
    if(++it == dictionary.end()){
        high = 1;
    }
    else{
        high = it->second;
    }
    s = range.encode_symbol(low, high);
    answer = answer + s;
    answer = answer + '1';
    return answer;
}

string Arithmetic::decode(string binary, Map dictionary, int length){
    cout << "Arithmetic decoding" << endl;
    Map::iterator it = dictionary.begin();
    double accumulate = 0;
    for(; it != dictionary.end(); it++){
        accumulate = accumulate + it->second;
        it->second = accumulate;
    }
    for(int i=0; i<length; i++){
        binary = binary + "0";
    }

    Range range;
    Bits bits(length, binary);
    string answer = "";
    string s = "";
    double x = bits.get_next();
    while(!range.end){
        s = range.decode_symbol(x, dictionary);
        x = bits.get_next();
        answer += s;
        if(answer.size() % 10000 == 0){
            cout << "decoding: " << answer.size() << " / " << temp << endl;
        }
    }
    return answer;
}