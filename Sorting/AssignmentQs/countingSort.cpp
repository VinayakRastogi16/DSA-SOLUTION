#include <iostream>
#include <climits>
using namespace std; 
void print(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
}

void countingSort(int *arr, int n){
    
    int freq[10000]= {0};
    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);
    }
    
    for (int i = maxVal, j = 0; i >= minVal; i--)
    {
        while (freq[i]>0)
        {
            arr[j++]= i;
            freq[i]--;
        }
        
    }

    print(arr,n);

}

int main(){
    int arr[] = {3,6,2,1,8,7,4,5,3,1};
    countingSort(arr,10);

    return  0;
}