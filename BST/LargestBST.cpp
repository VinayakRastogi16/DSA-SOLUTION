#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
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

class Info{
public:
    bool isBST;
    int mini;
    int maxi;
    int sz;

    Info(bool isBST, int mini, int maxi, int sz){
        this->isBST = isBST;
        this->mini = mini;
        this->maxi = maxi;
        this->sz = sz;
    }
};

static int maxSize;

Info* largestBST(Node* root){

    if(!root){
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    // if(!root){
    //     return NULL;
    // }

    // if(!root->left && !root->right){
    //     return new Info(true, root->data, root->data, 1);
    // }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->mini, rightInfo->mini));
    int currMax = max(root->data, max(leftInfo->maxi, rightInfo->maxi));;
    int currSize = leftInfo->sz+rightInfo->sz+1;


    if(leftInfo->isBST && rightInfo->isBST
    && root->data>leftInfo->maxi && root->data<rightInfo->mini){
        
        maxSize = max(maxSize, currSize);

        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}


int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout<<maxSize<<endl;

    return 0;
}