#include <util.h>


// Warning: some special words can't not show correctly
Map get_dictionary(string content){
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
        cout << it->first << ' ' << it->second << endl;
    }
    return dictionary;
}