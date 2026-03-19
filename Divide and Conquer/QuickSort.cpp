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

int partitionDescending(vector<int> &arr, int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for (int j = si; j < ei; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

        i++;
        swap(arr[i], arr[ei]);
        return i;
        
    
    
}

int partitionAscending(vector<int> &arr, int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for (int j = si; j < ei; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

        i++;
        swap(arr[i], arr[ei]);
        return i;
        
    
    
}

void quickSort1(vector<int> &arr, int si, int ei){
    if (si>=ei)
    {
        return;
    }

    int pivotIdx = partitionDescending(arr,si,ei);

    quickSort1(arr,si, pivotIdx-1);
    quickSort1(arr, pivotIdx+1, ei);
    

}

void quickSort2(vector<int> &arr, int si, int ei){
    if (si>=ei)
    {
        return;
    }

    int pivotIdx = partitionAscending(arr,si,ei);

    quickSort2(arr,si, pivotIdx-1);
    quickSort2(arr, pivotIdx+1, ei);
    

}



int main(){

    vector<int> arr = {6,3,7,5,2,4};

    quickSort2(arr, 0, arr.size()-1);
    print(arr);

    return 0;
}