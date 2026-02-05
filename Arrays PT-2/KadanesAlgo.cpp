#include <iostream>
#include <climits>
using namespace std;


void kadane(int *arr, int n){
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum<0)
        {
            currSum = 0;
        }
        
    }
    cout<<"Maximum Sum = "<< maxSum <<endl;
    

}

int main(){
    int arr[6] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);



    kadane(arr,n);


    return 0;
}