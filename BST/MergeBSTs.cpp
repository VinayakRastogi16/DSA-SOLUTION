#include<iostream>
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

void inOrder(Node* root, vector<int>& arr){
    if(!root){
        return;
    }

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}



Node* balancedBST(vector<int>& arr, int st, int end){

    if(arr.empty()){
        return NULL;
    }

    if(st>end)return NULL;

    int mid = st+(end-st)/2;

    Node* curr = new Node(arr[mid]);
    curr->left = balancedBST(arr, st, mid-1);
    curr->right = balancedBST(arr, mid+1, end);

    return curr;
}



Node* mergeBST(Node* r1, Node* r2){
    vector<int> r1a;
    vector<int> r2a;
    vector<int> merged;
    inOrder(r1, r1a);
    inOrder(r2, r2a);

    int i = 0; 
    int j = 0;

    while(i<r1a.size()&&j<r2a.size()){
        if(r1a[i]<r2a[j]){
            merged.push_back(r1a[i]);
            i++;
        }else{
            merged.push_back(r2a[j]);
            j++;
        }
    }

    while(i<r1a.size()){
        merged.push_back(r1a[i]);
        i++;
    }

    while(j<r2a.size()){
        merged.push_back(r2a[j]);
        j++;
    }


    return balancedBST(merged, 0, merged.size()-1);

}



void printTree(Node* root){
    if(!root){
        return;
    }

    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node* r1 = new Node(2);
    r1->left = new Node(1);
    r1->right = new Node(4);

    Node* r2 = new Node(9);
    r2->left = new Node(3);
    r2->right = new Node(12);

    Node* newRoot = mergeBST(r1, r2);

    printTree(newRoot);
    cout<<endl;
    return 0;
}