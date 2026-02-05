#include <iostream>
#include <climits>
using namespace std;


void maxSubArraySum(int *arr, int n){
    
    
    int maxSum = INT_MIN;

    for(int start = 0; start<n; start++){
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum += arr[i];
            }
            maxSum = max(maxSum,currSum);
        }
        
    }
    cout<<maxSum<<endl;
}

void maxSubArraySum2(int *arr, int n){
    
    
    int maxSum = INT_MIN;

    for(int start = 0; start<n; start++){
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);

        }
        
    }
    cout<<maxSum<<endl;
}

void kadane(int *arr, int n){
    
    
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i = 0; i<n; i++){
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0){

            currSum = 0;
        }
        
        
    }
    cout<<maxSum<<endl;
}


int main(){

    int arr[] = {23,54,2,-2,-9,4,6};

    int n = sizeof(arr)/sizeof(int);

    kadane(arr,n);


    return 0;


}