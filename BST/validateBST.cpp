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

void out(vector<int>& path){
    for(int i = 0; i< path.size(); i++)
        cout<<path[i]<<" ";

    return;
}

void printPath(vector<int>& path, Node* root){
    if(!root){
        return;
    }
    path.push_back(root->data);
    if(!root->left&&!root->right){
        out(path);
        cout<<endl;
        path.pop_back();
        return;
    }
    printPath(path,root->left);
    printPath(path,root->right);

    path.pop_back();
}

bool validate(Node* root, Node* mini, Node* maxi){
    if(root == NULL)return true;

    if(mini && root->data<mini->data){
        return false;
    }

    if(maxi && root->data>maxi->data){
        return false;
    }

    return validate(root->left, mini, root) && validate(root->right, root, maxi);
}

bool validateBSt(Node* root){
    return validate(root, NULL, NULL);
}

int main(){

    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    vector<int> path;
    Node* root = buildBST(arr,arr.size());
    
    cout<<validateBSt(root)<<endl;

    return 0;
}