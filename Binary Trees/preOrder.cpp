#include<iostream>
#include<algorithm>
#include<vector>
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

void printTree(Node* root){
    
    if(!root){
        // cout<<"-1, ";
        return;
    }

    cout<<root->data<<", ";
    printTree(root->left);
    printTree(root->right);
}

void inorder(Node* root){
    
    if(!root){
        // cout<<"-1, ";
        return;
    }

    
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

void postorder(Node* root){
    
    if(!root){
        // cout<<"-1, ";
        return;
    }

    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<", ";
    
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    postorder(root);
    cout<<endl;
    return 0;
}