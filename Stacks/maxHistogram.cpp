#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxHist(vector<int>& height){
    int n= height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i<n; i++){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    s.push(n-1);
    nsr[n-1] = n;
    for(int i = n-2; i>=0; i--){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;

    for(int i =0; i<n; i++){
        int ht = height[i];
        int width = nsr[i] - nsl[i] -1;
        int area = ht*width;

        maxArea = max(area, maxArea);
    }

    return maxArea; 
}


int main(){
    vector<int> hist = {2, 1, 5, 6, 2, 3};

    int ans = maxHist(hist);

    cout<<ans<<endl;
    return 0;

}