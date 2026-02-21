#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> vec, int target){
    int i = 0;
    int j = vec.size()-1;
    int currSum = 0;
    vector<int> ans;
    while (i<j)
    {
        currSum = vec[i] + vec[j];
        if (currSum == target)
        {
           ans.push_back(i);
           ans.push_back(j);
           return ans;
        }else if (currSum > target)
        {
            j--;
        }else{
            i++;
        }
        
    }

    return ans;
}

int main(){
    vector<int> vec = {2,7,11,15};
    vector<int> ans = pairSum(vec, 9);

    cout<<ans[0]<<", "<<ans[1]<<endl;

    return 0;
}