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




int transform(Node* root){
    if(root==NULL)return 0;

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld+rightOld;

    if(root->left){
        root->data+=root->left->data;
    }

    if(root->right){
        root->data+=root->right->data;
    }

    return currOld;
}

void levelOrder(Node* root){

    if(root == NULL)return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        
    }

}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    levelOrder(root);

    transform(root);

    levelOrder(root);
    return 0;
}