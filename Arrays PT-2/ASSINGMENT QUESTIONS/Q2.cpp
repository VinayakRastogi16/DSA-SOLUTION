#include <iostream>
using namespace std;

int searchRotated(int *nums, int n, int key) {

    int st = 0, end = n-1;

    while(st<=end){
        int mid = (st+end)/2;
        if (nums[mid]==key)
        {
            return mid;
        }
        else if (nums[st]<=nums[mid])
        {
            if (nums[st]<= key && key<nums[mid])
            {
                end = mid-1;
            }else{
                st = mid+1;
            }
            
        }
        else
        {
           if (nums[mid]<key && key <= nums[end])
           {
            st = mid+1;
           }else{
            end= mid-1;
           }
           
        }
        
    }
    return -1;

}

int main() {
    int nums[] = {4,5,6,7,0,1,2};  // rotated
    int n = sizeof(nums) / sizeof(int);

    cout << searchRotated(nums, n, 4) << endl; // prints 4
    return 0;
}