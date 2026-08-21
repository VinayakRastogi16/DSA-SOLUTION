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

void topView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> mp;

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* curNode = curr.first;
        int HD = curr.second;

        if(mp.count(HD)==0){
            mp[HD] = curNode->data;
        }

        if(curNode->left!=NULL){
            pair<Node*, int> left = make_pair(curNode->left, HD-1);
            q.push(left);
        }

        if(curNode->right!=NULL){
            pair<Node*, int> right = make_pair(curNode->right, HD+1);
            q.push(right);
        }
    }

    for(auto it: mp){
        cout<<it.second<<" ";
    }

}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    topView(root);
    cout<<endl;
    return 0;
}