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

Node* buildBSTfromSorted(vector<int>& arr, int st, int end){
    
    if(st>end){
        return NULL;
    }

    int mid = st+(end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root, vector<int>& sorted){
    if(root == NULL) return;

    
    inOrder(root->left, sorted);
    sorted.push_back(root->data);
    inOrder(root->right, sorted);
}


int main(){
    vector<int> arr = {3,4,5,6,7,8,9};
    vector<int> sorted;
    Node* root = buildBSTfromSorted(arr, 0, arr.size()-1);

    inOrder(root, sorted);
    for(int i:sorted){
        cout<<i<<" ";
    }
    cout<<endl;

    Node* newRoot = buildBSTfromSorted(sorted, 0, sorted.size()-1);

    preOrder(newRoot);
    cout<<endl;

    return 0;
}