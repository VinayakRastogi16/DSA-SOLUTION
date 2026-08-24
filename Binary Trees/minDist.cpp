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

int pathDist(Node* root, int n){

    if(root == NULL) return -1;

    if(root->data == n)return 0;

    int leftDist = pathDist(root->left, n);

    if(leftDist!=-1)return 1+leftDist;

    int rightDist = pathDist(root->right, n);

    if(rightDist!=-1)return 1+rightDist;

    return -1;
}

Node* LCA(Node* root, int n1, int n2){
    if(root==NULL)return NULL;

    if(root->data == n1 || root->data==n2)return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA!=NULL&&rightLCA!=NULL)return root;

    return leftLCA == NULL?rightLCA:leftLCA;
}

int minDist(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);

    int dist1 = pathDist(lca, n1);
    int dist2 = pathDist(lca, n2);

    return dist1+dist2;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 3;

    cout<<minDist(root, n1, n2)<<endl;
    return 0;
}