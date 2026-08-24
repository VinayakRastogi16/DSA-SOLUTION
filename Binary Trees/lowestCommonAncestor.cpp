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

bool path(Node* root, int n, vector<int>& p){
    if(root == NULL)return false;

    p.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = path(root->left, n, p);
    int isRight = path(root->right, n, p);

    if(isLeft||isRight)return true;

    p.pop_back();
    return false;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA!=NULL&& rightLCA!=NULL)return root;

    return leftLCA == NULL?rightLCA:leftLCA;
}

int lca(Node* root, int n1, int n2){
    vector<int> p1;
    vector<int> p2;

    path(root, n1, p1);
    path(root, n2, p2);

    int lca = -1;
    for(int i = 0, j=0; i<p1.size()&& j<p2.size(); i++, j++){
        if(p1[i]!=p2[j]){
            return lca;
        }
        lca = p1[i];
    }

    return lca;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 5;

    cout<<LCA2(root, n1, n2)->data<<endl;
    return 0;
}