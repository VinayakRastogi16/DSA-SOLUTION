#include <iostream>

using namespace std;

void spiralMatrix(int arr[3][4], int n, int m){

    int srow=0, scol=0, erow=n-1, ecol=m-1;

    while (srow <= erow && scol <= ecol)
    {
        for (int j = scol; j <= ecol ; j++) //for Top
        {
            cout<<arr[srow][j]<<", ";
        }


        for (int i = srow+1; i <= erow ; i++) //for Right
        {
            cout<<arr[i][ecol]<<", ";
        }


        for (int j = ecol-1; j >= scol ; j--) //for Bottom
        {
            if (srow==erow)
            {
                break;
            }
            
            cout<<arr[erow][j]<<", ";
        }

        
        for (int i = erow-1; i >= srow+1 ; i--) //for Left
        {
            if (scol==ecol)
            {
                break;
            }
            
            cout<<arr[i][scol]<<", ";
        }

        srow++;erow--;
        scol++;ecol--;
    }
    cout<<endl;
    
    

}

int main(){
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int arr2[3][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}};
    spiralMatrix(arr2, 3,4);

    return 0;
}