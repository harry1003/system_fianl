#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"
using namespace std;

class Arithmetic{
public:
    Arithmetic(){};
    string encode(string content, Map dictionary);
};

class Range{
public:
    Range(){low = 0; high = 1; follow=0;}
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
                for(int i=0; i<follow; i++){
                    binary = binary + "1";
                }
                follow = 0;

                low = low * 2;
                high = high * 2;
            }
            else if(low >= 0.5){
                binary = binary + "1";
                for(int i=0; i<follow; i++){
                    binary = binary + "0";
                }
                follow = 0;

                high = 1 - (1 - high) * 2;
                low = 1 - (1 - low) * 2;
            }
            else if(low >= 0.25 && high <= 0.75){
                follow = follow + 1;

                double h_d = (0.75 - high) * 2;
                double l_d = (low - 0.25) * 2;
                high = 1 - h_d;
                low = 0 + l_d;
            }
            else{
                return binary;
            }

            if(low > high){
                cout << "Unexpected Error at encode_symbol" << endl;
                exit(1);
            }
        }
        cout << "Unexpected Error at encode_symbol" << endl;
        exit(1);
    }

    string end(){
        return "1";
    }

private:
    double low, high;
    int follow;
};