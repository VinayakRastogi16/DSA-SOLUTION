#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int singleNumber(vector<int>& nums){ //O(n*logn)
    sort(nums.begin(),nums.end());
    int i =0;
    while (i<nums.size()-1)
    {
        if ((nums[i]^nums[i+1])==0)
        {
            i+=2;

        }else{
            return nums[i];
        }
        
    }

    return nums[nums.size()-1];
}

int singleNumber2(vector<int>& nums) { //O(n)-> optimal solution
    int ans =0;
    for(int x: nums){
        ans ^= x;
    }
    return ans;
    }

int main(){
    vector<int> nums = {1,5,1,2,2,3,4,3,4,6,7,7,8,6,8};
    cout<<singleNumber(nums)<<"\n";

    return 0;

}