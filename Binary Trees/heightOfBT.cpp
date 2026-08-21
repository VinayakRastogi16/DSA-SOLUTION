#include<iostream>
#include<algorithm>
#include<vector>
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

int height(Node* root){
    Node* curr = root;
    if(curr == NULL){
        return 0;
    }

    int leftH = height(curr->left);
    int rightH = height(curr->right);

    int height = max(leftH, rightH) + 1;

    return height;
}

int count(Node* root){
    Node* curr = root;
    if(curr == NULL){
        return 0;
    }

    int leftCnt = count(curr->left);
    int rightCnt = count(curr->right);

    int count = leftCnt + rightCnt + 1;

    return count;
}

int diameter(Node* root){

    if(root == NULL){
        return 0;
    }

    int currDiam = height(root->left)+height(root->right)+1;
    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);

    return max(rightDiam, max(leftDiam, currDiam));
}

int totSum(Node* root){
    Node* curr = root;
    if(curr == NULL){
        return 0;
    }

    int leftSum =totSum(curr->left);
    int rightSum = totSum(curr->right);

    int totalSum = leftSum+rightSum+curr->data;

    return totalSum;
}

pair<int, int> diam2(Node* root){
    if(root == NULL){
        return make_pair(0, 0);
    }

    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root->right);

    int currDiam = leftInfo.second+rightInfo.second+1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second)+1;

    return make_pair(finalDiam, finalHt);

}


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




int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // levelOrder(root);
    // cout<<endl;

    cout<<height(root)<<endl;
    cout<<count(root)<<endl;
    int x = totSum(root);

    pair<int, int> diam = diam2(root);

    cout<<x<<endl;
    cout<<diameter(root)<<endl;
    cout<<diam.first<<endl;

    return 0;
}