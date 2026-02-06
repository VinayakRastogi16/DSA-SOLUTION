#include <iostream> 
#include <algorithm>
using namespace std;


int isRepeated(int *nums, int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j <n; j++)
        {
            if (nums[i]==nums[j])
            {
                
                return 1;
            }
            
        }
        
    }
    return 0;
    
}

bool isRepeated2(int *nums, int n){
    sort(nums, nums+n);

    for (int i = 1; i < n; i++)
    {
        if(nums[i]==nums[i-1]){
            return true;
        }

    }
    return false;
    
}


int main(){

    int nums[] = {2,5,1,4,7,9};
    int n = sizeof(nums)/sizeof(int);

    cout<<isRepeated2(nums, n )<<endl;

    return 0;

}