#include <iostream> 
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


int main(){

    int nums[] = {1,4,5,3,4,67,8};
    int n = sizeof(nums)/sizeof(int);

    cout<<isRepeated(nums, n )<<endl;

    return 0;

}