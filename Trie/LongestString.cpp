#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> child;
    bool isEnd;

    Node()
    {
        isEnd = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
            {
                temp->child[key[i]] = new Node();
            }
            temp = temp->child[key[i]];
        }

        temp->isEnd = true;
    }

    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
            {
                return false;
            }

            temp = temp->child[key[i]];
        }

        return temp->isEnd;
    }

    void longestHelper(Node *root, string &ans, string temp)
    {
        for (pair<char, Node *> child : root->child)
        {
            if (child.second->isEnd)
            {
                temp += child.first;

                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size()))
                {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    string longestString()
    {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestStr(vector<string> &dict)
{
    Trie t;

    for (int i = 0; i < dict.size(); i++)
    {
        t.insert(dict[i]);
    }

    return t.longestString();
}

int main()
{
    vector<string> words = {"a", "banana", "app", "ap", "apply", "appl"};
    cout << longestStr(words) << endl;
    return 0;
}