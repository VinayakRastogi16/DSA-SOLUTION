#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;

        for(int i = 0; i< key.size(); i++){
            idx = idx+(key[i]*key[i])%totSize;
        }

        return idx%totSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];

        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }

        //copy old values
        for(int i =0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:

    HashTable(int size = 5){
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){ //O(1) for avg cases
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda>1){ //O(n) for worst cases
            rehash();
        }
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp){
            if(temp->key == key){
                if(temp == prev){
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }

                break;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp){
            if(temp->key == key)return true;

            temp = temp->next;
        }

        return false;
    }

    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp){
            if(temp->key == key)return temp->val;

            temp = temp->next;
        }

        return -1;
    }

    void print(){
        for(int i = 0; i<totSize; i++){
            cout<<"idx"<< i<<"->";
            Node* temp = table[i];
            while(temp){
                cout<<"("<<temp->key<<" ,"<<temp->val<<")->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};


int main(){

    HashTable ht;

    ht.insert("India", 150);
    ht.insert("Nepal", 10);
    ht.insert("China", 180);
    ht.insert("Singapore", 15);
    ht.insert("Japan", 50);
    ht.insert("UK", 75);
    ht.insert("US", 90);
    ht.insert("Africa", 150);

    // if(ht.exists("Africa")){
    //     cout<<"Africa : "<<ht.search("Africa")<<endl;
    // }

    ht.print();

    ht.remove("Africa");
    cout<<"-----------------------------------------\n";
    ht.print();

    ht.remove("UK");
    cout<<"-----------------------------------------\n";
    ht.print();

    return 0;
}