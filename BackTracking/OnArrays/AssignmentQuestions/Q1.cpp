#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveMazeUtil(vector<vector<int>> &maze, int x, int y, string sol, int n, vector<vector<bool>> &vis){

    if (x == n-1 && y == n-1 && maze[x][y]==1)
    {
        cout<<sol<<"\n";
        return;
    }

    if(x-1>=0 && !vis[x-1][y] && maze[x-1][y]==1){
        vis[x][y] = true;
        solveMazeUtil(maze, x-1, y, sol+'U', n, vis);
        vis[x][y] = false;
    }

    if(x+1<n && !vis[x+1][y] && maze[x+1][y]==1){
        vis[x][y] = true;
        solveMazeUtil(maze, x+1, y, sol+'D', n, vis);
        vis[x][y] = false;
    }

    if(y+1<n && !vis[x][y+1] && maze[x][y+1]==1){
        vis[x][y] = true;
        solveMazeUtil(maze, x, y+1, sol+'R', n, vis);
        vis[x][y] = false;
    }

    if(y-1>=0 && !vis[x][y-1] && maze[x][y-1]==1){
        vis[x][y] = true;
        solveMazeUtil(maze, x, y-1, sol+'L', n, vis);
        vis[x][y] = false;
    }
    

}

void Ways(vector<vector<int>> &maze, int n){
    string sol = "";

    vector<vector<bool>> vis(n, vector<bool> (n, false));

    if (maze[0][0]==1){
        solveMazeUtil(maze, 0,0, sol, n , vis);
    }

}

int main()
{
    int n =4;

    vector<vector<int>> maze = {{1, 0, 0, 0}, 
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0}, 
                                {0, 1, 1, 1}};

    Ways(maze, n);

    return 0;
}