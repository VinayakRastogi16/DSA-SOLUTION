#include<iostream>
#include<vector>
using namespace std;

int xorBeauty(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans ^= ((nums[i]|nums[j])&nums[k]);
            }
            
        }
        
    }


    
    return ans;
    
}

int xorBeauty2(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans ^= nums[i];
    }
    
    return ans;
    
}


int main(){
    vector<int> nums = {15,45,20,2,34,35,5,44,32,30};
    cout<<xorBeauty2(nums)<<endl;
    cout<<(15^45^20^2^34^35^5^44^32^30)<<endl;

    return 0;
}