#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatedAndMissingNum(vector<int>& nums){
    int n = nums.size();

    vector<int> freq(n+1, 0);
    vector<int> error(2);

    for(int x : nums){
        freq[x]++;
    }

    for (int i = 0; i < n+1; i++)
    {
        if(freq[i]==2){
            error[0] = i;
        }
        if (freq[i]==0)
        {
            error[1] = i;
        }
        
    }

    return error;
     
}


int main(){
    vector<int> nums = {1,2,3,2};
    auto res = repeatedAndMissingNum(nums);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}