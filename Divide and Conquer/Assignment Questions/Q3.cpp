#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}


long long merge(vector<int> &arr, int si, int ei, int mid){
    long long inv = 0;
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){
        if (arr[i]<=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            inv += (mid-i+1);
            j++;
        }
        
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j<=ei)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = si, x=0; i <= ei; i++)
    {
        arr[i] = temp[x++];
    }

    return inv;

}

long long mergeSort(vector<int> &arr, int si, int ei){

    if(si>=ei){
        return 0;
    }

    int mid = si +(ei-si)/2;

    long long left = mergeSort(arr, si, mid);
    long long right = mergeSort(arr, mid+1, ei);
    long long mergeInv =  merge(arr, si, ei, mid);

    return left + right + mergeInv;
}

int main(){

    vector<int> arr = {1};
    cout<<mergeSort(arr, 0, arr.size()-1)<<endl;
    return 0;
}