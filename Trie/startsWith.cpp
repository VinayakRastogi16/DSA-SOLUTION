#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node(){
        isEnd = false;
    }
};

class Trie{
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->child.count(key[i]) == 0){
                temp->child[key[i]] = new Node();
            }

            temp = temp->child[key[i]];
        }

        temp->isEnd = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->child.count(key[i])==0){
                return false;
            }

            temp = temp->child[key[i]];
        }

        return temp->isEnd;
    }

    bool startsWith(string prefix){
        Node* temp = root;

        for(int i = 0; i<prefix.size(); i++){
            if(temp->child[prefix[i]]){
                temp = temp->child[prefix[i]];
            }else{
                return false;
            }
        }

        return true;
    }
};

int main(){

    vector<string> words = {"app", "apple", "woman", "man", "mango"};
    Trie t;

    for(int i = 0; i<words.size(); i++){
        t.insert(words[i]);
    }

    cout<<t.startsWith("wom")<<endl;
    return 0;
}