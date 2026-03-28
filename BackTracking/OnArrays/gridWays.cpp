#include<iostream>
#include<vector>
#include<string>

using namespace std;

int gridWays(int r, int c, int n, int m, string steps){
    if (r==n-1&&c==m-1)
    {
        cout<<steps<<endl;
        return 1;
    }

    if (r>=n || c >=m)
    {
        return 0;
    }
    
    
    int v1 = gridWays(r,c+1,n,m, steps+'R');
    int v2 = gridWays(r+1,c,n,m, steps+'D');

    return v1+v2;
}

int main(){
    int n =3;
    int m =3;
    string steps;
    int ans = gridWays(0,0,n,m, steps);
    cout<<"No. of Ways = "<<ans<<endl;

    return 0;
}