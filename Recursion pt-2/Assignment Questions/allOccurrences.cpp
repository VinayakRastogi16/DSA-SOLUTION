#include<iostream>
#include<vector>

using namespace std;

vector<int> allOccurences(vector<int> &arr, vector<int> &ans, int key, int i){
    if (i==arr.size())
    {
        return ans;
    }

    if (key == arr[i])
    {
        ans.push_back(i);
    }

    return allOccurences(arr, ans, key, i+1);
    
    

}

int main(){
    vector<int> arr = {3,2,4,5,6,2,7,2,2};
    vector<int> ans;
    allOccurences(arr,ans, 2, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}