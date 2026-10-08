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
            if(temp->child.count(key[i])==0){
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

    int countHelper(Node* root){
        int ans = 0;

        for(pair<char, Node*> child:root->child){
            ans+=countHelper(child.second);
        }

        return ans+1;
    }

    int countNodes(){
        return countHelper(root);
    }

};

int cntUniqSubstr(string str){
    Trie t;
    for(int i = 0; i<str.size(); i++){
        string suffix = str.substr(i);
        t.insert(suffix);
    }

    return t.countNodes();
}

int main(){
    string s = "ababa";

    cout<<cntUniqSubstr(s)<<endl;
    return 0;
}