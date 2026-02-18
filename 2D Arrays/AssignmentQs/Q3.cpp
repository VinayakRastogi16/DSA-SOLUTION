#include <iostream>

using namespace std;


void print(int trans[][4], int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<trans[i][j]<<" ,";
        }
        cout<<endl;
    }
    
}

void transpose(int arr[][4], int n, int m){


    int trans[4][4]={0};


    

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            
            trans[i][j] = arr[j][i];
        }
        
    }


    print(trans, 4,4);
    
}

int main(){
    int arr[4][4] = {{4,7,7,9}, {8,2,8,7},{3,4,2,1},{4,2,12,3}};

    transpose(arr, 4,4);
    return 0;
}