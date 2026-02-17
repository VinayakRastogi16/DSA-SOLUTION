#include <iostream>
using namespace std;

bool searchSorted(int arr[][4], int n, int m, int key)
{
     int i = 0, j = m-1;

     while (i<n && j>=0)
     {
        if (arr[i][j]==key)
        {
            cout<<"Found at index ["<< i<<","<<j<<"]";
            cout<<endl;

            return 1;
        }
        else if (arr[i][j]>key) //left
        {
            j--;
        }
        else //down
        {
            i++;
        }
        
     }

     cout<<"Key not found.\n";
     return 0;
     
}

bool searchSorted2(int arr[][4], int n, int m, int key)
{
     int i = n-1, j = 0;

     while (j<m && i>=0)
     {
        if (arr[i][j]==key)
        {
            cout<<"Found at index ["<< i<<","<<j<<"]";
            cout<<endl;

            return 1;
        }
        else if (arr[i][j]<key) //right
        {
            j++;
        }
        else //up
        {
            i--;
        }
        
     }

     cout<<"Key not found.\n";
     return 0;
     
}

int main()
{
    int arr[4][4] =    {{10, 20, 30, 40}, 
                        {15, 25, 35, 45}, 
                        {27, 29, 37, 48}, 
                        {32, 33, 39, 50}};

    searchSorted(arr,4,4,45);
    return 0;
}