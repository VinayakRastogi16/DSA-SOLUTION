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

Node* getInorderSuccessor(Node* root){
    while(root->left!=NULL){
        getInorderSuccessor(root->left);
    }

    return root;
}

Node* delNode(Node* root, int val){
    if(!root)
        return NULL;
    
    if(val<root->data){
        root->left=delNode(root->left, val);
    }else if(val>root->data){
        root->right=delNode(root->right, val);
    }else{
        // case 1: 0 CHILD
        if(!root->left&&!root->right){
            delete root;
            return NULL;
        }
        // case 2: 1 CHILD
        if(!root->left||!root->right){
            return root->left==NULL?root->right:root->left;
        }

        // case 3: 2 CHILDREN

        Node* successor = getInorderSuccessor(root->right);
        root->data = successor->data;
        root->right = delNode(root->right, successor->data);


    }

    return root;
}

void printRange(Node* root, int st, int end){

    if(!root) return;

    if(root->data>=st && root->data<=end){
        
        printRange(root->left, st, end);
        cout<<root->data<<" ";
        printRange(root->right, st, end);
    }else if(root->data<st){
        printRange(root->right, st, end);
    }
    if(root->data>end){
        printRange(root->left, st, end);
    }
}


int main(){

    vector<int> arr = {5,1,3,4,2,6,11,8,10,14};
    Node* root = buildBST(arr,arr.size());
    printRange(root, 5, 12);
    cout<<endl;

    return 0;
}