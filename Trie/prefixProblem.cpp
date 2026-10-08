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
    int freq;

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
        root->freq = -1;
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
            {
                temp->child[key[i]] = new Node();
                temp->child[key[i]]->freq = 1;
            }
            else
            {
                temp->child[key[i]]->freq++;
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

    string getPrefix(string key)
    { // O(n*L)
        Node *temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++)
        {
            prefix += key[i];
            if (temp->child[key[i]]->freq == 1)
            {
                break;
            }
            temp = temp->child[key[i]];
        }

        return prefix;
    }
};

void prefixProblem(vector<string> &dict)
{
    Trie t;

    for (int i = 0; i < dict.size(); i++)
    {
        t.insert(dict[i]);
    }

    for (int i = 0; i < dict.size(); i++)
    {
        cout << t.getPrefix(dict[i]) << endl;
    }
}

int main()
{

    vector<string> dict = {"zebra", "dog", "duck", "dove"};

    prefixProblem(dict);
    return 0;
}