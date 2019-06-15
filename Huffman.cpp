#include <queue>
#include "./Huffman.h"

string Huffman::encode(string content, Map dictionary){
    cout << "Huffman encoding" << endl;
    cout << "building tree" << endl;
    buildMap(dictionary);

    cout << "start encoding" << endl;
    string answer;
	for(size_t i=0; i<content.size(); i++){
		string s(1, content[i]);
		answer += this->symbol_map[s];
        
        if(i % 100000 == 0){
            cout << "encoding: " << i << " / " << content.size() << endl;
        }
    }
	return answer;
}

string Huffman::decode(string binary, Map dictionary){
    cout << "Huffman decoding" << endl;
    cout << "building tree" << endl;
    buildMap(dictionary);

    cout << "start decoding" << endl;
    string answer;
    Node* curr = root; 
    for(size_t i=0; i<binary.size(); i++){ 
        if(binary[i] == '0') 
           curr = curr->left; 
        else
           curr = curr->right; 
        if(curr->left == NULL && curr->right == NULL){ 
            answer += curr->data; 
            curr = root; 
        } 
        if(i % 100000 == 0){
            cout << "decoding: " << i << " / " << binary.size() << endl;
        }
    } 
    return answer; 
}

void Huffman::buildMap(Map& dictionary){
    root = buildTree(dictionary);
    set_data(this->symbol_map, root, "");
}

Node* Huffman::buildTree(Map& dictionary){
    priority_queue<Node*, vector<Node*>, CompareNode> node_list;
    Map::iterator it = dictionary.begin();
    for(; it != dictionary.end(); it++){
    	string data = it->first;
    	Node* node = createNode(data, it->second, NULL, NULL);
        node_list.push(node);
    }
    
    while(node_list.size() > 1){
        Node* node1 =  node_list.top();
        node_list.pop();
        Node* node2 =  node_list.top();
        node_list.pop();
        Node* new_node = createNode("", node1->p + node2->p, node1, node2);
        node_list.push(new_node);
    }
    return node_list.top();
}

void Huffman::set_data(unordered_map<string, string>& symbol_map, Node* node, string binary){
	if(node->left == NULL && node->right == NULL){
		symbol_map.insert(make_pair(node->data, binary));
		return;
	}
	if(node->left != NULL){
		string new_binary = binary + "0";
		set_data(symbol_map, node->left, new_binary);
	}
	if(node->right != NULL){
		string new_binary = binary + "1";
		set_data(symbol_map, node->right, new_binary);
	}
}

Node* Huffman::createNode(string data, double p, Node* left, Node* right){
    Node* node = new Node;
	node->data = data;
	node->p = p;
    node->left = left;
    node->right = right;
    return node;
}

