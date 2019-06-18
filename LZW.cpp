// change from https://rosettacode.org/wiki/LZW_compression#C.2B.2B
#include "./LZW.h"


vector<string> LZW::encode(string source){
	cout << "LZW encoding" << endl;

	unordered_map<string, int> dictionary;
	unordered_map<string, int>::iterator it;

	// build dictionary
	int count = 0;
	for(; count < 256; count++){
		string symbol = string(1, count);
		dictionary.insert(make_pair(symbol, count));
	}

	vector<string> answer_list;
	string w = "";
	for(size_t i=0; i<source.size(); i++){
		char c = source[i];
		string wc = w + c;
		it = dictionary.find(wc);
		if(it != dictionary.end()){
			// wc is in the dictionary
			w = wc;
		}
		else{
			answer_list.push_back(to_string(dictionary.find(w)->second));
			dictionary.insert(make_pair(wc, count++));
			w = string(1, c);
		}
	}
	dictionary_size = dictionary.size();
	return answer_list;
}

string LZW::decode(vector<string> binary){
	cout << "LZW decoding" << endl;

	unordered_map<int, string> dictionary;
	unordered_map<int, string>::iterator it;

	// build dictionary
	int count = 0;
	for(; count < 256; count++){
		string symbol = string(1, count);
		dictionary.insert(make_pair(count, symbol));
	}

	string w = dictionary.find(atoi(binary[0].c_str()))->second;
	string answer = w;
	string entry = "";
	for(size_t i=1; i<binary.size(); i++){
		it = dictionary.find(atoi(binary[i].c_str()));
		if(it != dictionary.end()){
			// binary[i] is in the dictionary
			entry = it->second;
		}
		else if(atoi(binary[i].c_str()) == count){
			entry = w + w[0];
		}
		else{
			cout << answer << endl;
			cout << "Bad compression" << endl;
			exit(1);
		}
		answer = answer + entry;
		dictionary.insert(make_pair(count++, w + entry[0]));
		w = entry;
	}
	cout << "Decoding end" << endl;
	return answer;
}
