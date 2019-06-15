#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "util.h"


using namespace std;
class LZW{
public:
    LZW(){dictionary_size = 0;};
    vector<string> encode(string content);
    string decode(vector<string> binary);
    size_t dictionary_size;
};

