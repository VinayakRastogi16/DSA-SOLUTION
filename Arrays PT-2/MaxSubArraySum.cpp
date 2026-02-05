#include <iostream>
#include <climits>


using namespace std;

void maxSum(int *arr, int n){ //Brute Force
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++){
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum += arr[i];
                
            }
            cout<<currSum<<", ";
            maxSum = max(maxSum, currSum);
            
        }
        
        cout<<endl;
    }
    cout<<"Max sum = "<<maxSum<<endl;
    
    
}

void maxSum2(int *arr, int n){ //Optimal Approach
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++){
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
            
        }
        
    }
    cout<<"Max sum = "<<maxSum<<endl;
    
    
}

int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int n = 6;

    maxSum2(arr, n);

    return 0;
}