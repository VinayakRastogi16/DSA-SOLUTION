#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph(){
        for(int u=0;u<V;u++){
            list<int> neighbours = l[u];
            cout<<u<<" : ";
            for(int v:neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(){ // O(V+E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            list<int> neighbours = l[u];

            for(int v: neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }

        }

        cout<<endl;
    }

    void dfsHelper(int u, vector<bool>& vis){ //O(V+E)
        vis[u] = true;
        cout<<u<<" ";

        list<int> neighbours = l[u];
        for(int v: neighbours){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(7, false);
        dfsHelper(0, vis);
        cout<<endl;
    }

};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.dfs();

    return 0;
}