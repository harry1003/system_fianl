#include "./Arithmetic.h"


string Arithmetic::encode(string content, Map dictionary){
    Map::iterator it = dictionary.begin();
    double accumulate = 0;
    for(; it != dictionary.end(); it++){
        accumulate = accumulate + it->second;
        it->second = accumulate;
        cout << it->first << ' ' << it->second << endl;
    }

    string answer = "";
    string s = "";

    Range range;
    for(size_t i=0; i<content.size(); i++){
        string symbol(1, content[i]);
        it = dictionary.find(symbol);

        double high = it->second;
        double low = 

    }

    // s = range.encode_symbol(0.4, 0.9);
    // answer = answer + s;
    // s = range.encode_symbol(0.4, 0.9);
    // answer = answer + s;
    // s = range.encode_symbol(0.4, 0.9);
    // answer = answer + s;
    // s = range.encode_symbol(0.9, 1);
    // answer = answer + s;

    cout << answer << endl;
    return "fff";
}