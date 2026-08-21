#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int i = -1;

Node* buildTree(vector<int>& nodes){
    i++;

    if(nodes[i]==-1)
        return NULL;

    Node* currNode = new Node(nodes[i]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void kthHelper(Node* root, int k, int currLev){

    if(!root){
        return;
    }


    if(currLev == k){
        cout<<root->data<<" ";
        return;
    }

    kthHelper(root->left, k, currLev+1);
    kthHelper(root->right, k, currLev+1);
}

void kthLevel(Node* root, int k){
    kthHelper(root, k, 1);
    cout<<endl;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    kthLevel(root, 3);
    return 0;
}
