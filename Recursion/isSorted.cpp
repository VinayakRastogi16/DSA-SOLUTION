#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> &arr, int n,int i){
    if (i == n-1)
    {
        return true;
    }
    

    if (arr[i] > arr[i+1])
    {
        return false;
    }

    return isSorted(arr, n, i+1);
     


}

bool isSorted(int *arr, int n,int i){
    if (i == n-1)
    {
        return true;
    }
    

    if (arr[i] > arr[i+1])
    {
        return false;
    }

    return isSorted(arr, n, i+1);
     


}

int main(){
    vector<int> arr = {1,2,3,6,5};
    int arr2[5] = {1,2,3,4,5};
    cout<<isSorted(arr, 5, 0)<<endl;
    cout<<isSorted(arr2, 5, 0)<<endl;
    return 0;
}