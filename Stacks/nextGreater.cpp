#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int>& arr, vector<int>& ans){
    stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(int i = idx-1; i>=0; i--){
        int curr = arr[i];

        while (!s.empty() && s.top()<=curr)
        {
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();

        }
        
        s.push(curr);
    }


    return ans;
}

int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(arr.size(), 0);

    nextGreater(arr, ans);

    for(auto& x : ans){
        cout<<x<<" ";
    }

    cout<<endl;

    return 0;
}