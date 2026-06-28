#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end){
    vector<tuple<int, int, int>> ans;
    int n = start.size();

     for(int i = 0; i<n; i++){
        ans.push_back({end[i], start[i], i+1});
    }

     sort(ans.begin(), ans.end());
    vector<int> result;
    int lastEnd = -1;

     for(auto& m : ans){
        int e = get<0>(m);
        int s = get<1>(m);
        int idx = get<2>(m);

         if(s>lastEnd){
            result.push_back(idx);

             lastEnd = e;
        }
    }
 
    return result.size();

}


int main(){
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};

    int x = maxMeetings(start, end);

    cout<<"Max meetings that can be held in One meeting room are "<<x<<endl;

    return 0;
}
