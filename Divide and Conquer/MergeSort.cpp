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

void merge(vector<int> &arr, int si, int ei, int mid){ //O(n)

    vector<int> temp;
    int i = si;
    int j = mid+1;

    while (i<=mid && j<=ei)
    {
        if (arr[i]>arr[j])
        {
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
        
        
    }

    while (i<=mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j<=ei)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = si, x=0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }
    
    

}

void mergeAsceding(vector<int> &arr, int si, int ei, int mid){ //O(n)

    vector<int> temp;
    int i = si;
    int j = mid+1;

    while (i<=mid && j<=ei)
    {
        if (arr[i]<arr[j])
        {
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
        
        
    }

    while (i<=mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j<=ei)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = si, x=0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }
    
    

}

void mergeSort(vector<int> &arr, int si, int ei){ //O(n*log n)
    if (si>=ei)
    {
        return;
    }

    int  mid = si+(ei-si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid); //conquer
    
}

void mergeSort2(vector<int> &arr, int si, int ei){ //O(n*log n)
    if (si>=ei)
    {
        return;
    }

    int  mid = si+(ei-si)/2;
    mergeSort2(arr, si, mid);
    mergeSort2(arr, mid+1, ei);

    mergeAsceding(arr, si, ei, mid); //conquer
    
}





int main(){
    vector<int> arr = {6,3,7,5,2,4};
    mergeSort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}