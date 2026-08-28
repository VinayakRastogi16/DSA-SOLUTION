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

Node* insert(Node* root, int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    
    return root;
}

Node* buildBST(vector<int>& arr, int n){
    Node* root = NULL;

    for(int i=0;i<n;i++){
        root = insert(root, arr[i]);
    }

    return root;
}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool search(Node* root, int key){
    if(!root){
        return false;
    }

    if(root->data == key){
        return true;
    }else if(root->data>key){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }

    return false;
}

int main(){

    vector<int> arr = {5,1,3,4,2,6,8,9,43,232,7};
    Node* root = buildBST(arr,arr.size());

    cout<<search(root, 43);
    cout<<endl;

    return 0;
}