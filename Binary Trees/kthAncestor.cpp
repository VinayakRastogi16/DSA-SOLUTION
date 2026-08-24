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

int kthAncestor(Node* root, int val, int k){
    if(root == NULL)return -1;

    if(root->data == val)return 0;

    int leftDist = kthAncestor(root->left, val, k);
    int rightDist = kthAncestor(root->right, val, k);

    if(leftDist == -1 && rightDist == -1)return -1;

    int validVal = leftDist == -1 ? rightDist: leftDist;
    if(validVal+1 == k){
        cout<<root->data<<endl;
    }

    return validVal+1;
}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    kthAncestor(root, 6, 1);
    return 0;
}