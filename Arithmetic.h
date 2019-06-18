#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"
using namespace std;

class Arithmetic{
public:
    Arithmetic(){};
    string encode(string content, Map dictionary);
    string decode(string binary, Map dictionary, int length=256);
};

class Range{
public:
    Range(){low = 0; high = 1; follow=0; end=false;}
    string encode_symbol(double x1, double x2){
        if(x2 < x1){
            cout << "Error: x2 shoule > x1, but get x2 = " << x2 << ", x1 = " << x1 << endl;
            cout << endl;
        }
        string binary = "";
        double dis = (high - low);
        high = dis * x2 + low;
        low = dis * x1 + low;
        while(true){
            if(high <= 0.5){
                binary = binary + "0";
                low = low * 2;
                high = high * 2;
            }
            else if(low >= 0.5){
                binary = binary + "1";
                high = 2 * (high - 0.5);
                low = 2 * (low - 0.5);
            }
            else{
                return binary;
            }
        }
    }

    string decode_symbol(double x, Map& dictionary){
        string answer = "";
        while(true){
            if(high <= 0.5){
                high = high * 2;
                low = low * 2;
                return answer;
            }
            else if(low >= 0.5){
                high = 2 * (high - 0.5);
                low = 2 * (low - 0.5);
                return answer;
            }
            Map::iterator it = dictionary.begin();
            Map::iterator before = it;
            double rescale = (x - low) / (high - low);
           
            for(; it != dictionary.end(); it++){
                if(it->second > rescale){
                    if(it->first == "EOF"){
                        end = true;
                        return answer;
                    }
                    answer = answer + it->first;
                    break;
                }
                before = it;
            }
            // update high and low
            double dis = high - low;
            high = low + dis * it->second;
            if(it == before){
                low = low;
            }
            else{
                low = low + dis * before->second;
            }
        }
    }

    double low, high;
    int follow;
    bool end;
};

class Bits{
public:
    Bits(int l, string b){binary = b; length = l; current=0;}

    double get_next(){
        if(size_t(current + length) > binary.size()){
            cout << "Missing EOF" << endl;
            exit(1);
        }

        double answer = 0;
        double x = 0.5;

        for(int i=0; i<length; i++){
            if(binary[current + i] == '1'){
                answer = answer + x;
            }
            x = x / 2;
        }
        current = current + 1;
        return answer;
    }

    int length, current;
    string binary;
};