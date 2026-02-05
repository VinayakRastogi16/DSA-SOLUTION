#include <iostream>

using namespace std;

void largestProduct(int *nums, int n){

    int ans = nums[0];

    for (int i = 0; i < n; i++)
    {
        
       int currProd = 1;
        for (int j = i; j < n; j++)
        {
            currProd = currProd*nums[j];

            ans=max(currProd,ans);
        }
        

    }

    cout<<ans<<endl;
    
    
    

}



int main(){
    int nums[] = {2,3,-2,4};
    int n = sizeof(nums)/sizeof(int);

    largestProduct(nums,n);
    return 0;
}