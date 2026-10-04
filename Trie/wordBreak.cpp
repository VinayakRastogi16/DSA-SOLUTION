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

bool helper(Trie& t, string key){
    if(key.size()==0)return true;

    for(int i =0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(t.search(first)&&helper(t, second)){
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string>& dict, string key){
    Trie t;
    for(int i=0; i<dict.size(); i++){
        t.insert(dict[i]);
    }

    return helper(t, key);
}



int main(){

    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout<<wordBreak(dict, "ilikesam")<<endl;
    return 0;
}