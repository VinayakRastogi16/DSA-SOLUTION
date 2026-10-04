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
};

int main(){

    vector<string> words = {"the", "their", "a", "there", "any", "thee"};
    Trie t;

    for(int i = 0; i<words.size(); i++){
        t.insert(words[i]);
    }

    cout<<t.search("they")<<endl;
    return 0;
}