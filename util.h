#ifndef __UTIL_H__
#define __UTIL_H__


#include <iostream>
#include <string>
#include <unordered_map>
#include <unistd.h>
using namespace std;
typedef unordered_map<string, double> Map;

string read_bits(string filename);
Map get_dictionary_txt(string);

#endif