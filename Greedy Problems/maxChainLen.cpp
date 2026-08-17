#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}

int maxChain(vector<pair<int, int>>& p){

    int n = p.size();

    sort(p.begin(), p.end(), compare);

    int ans = 1;
    int currEnd = p[0].second;
    for(int i = 1; i<n; i++){
        if(p[i].first>currEnd){
            ans++;
            currEnd = p[i].second;
        }
    }

    return ans;
}

int main(){
    vector<pair<int, int>> p(5, make_pair(0,0));
    p[0] = make_pair(5, 24);
    p[1] = make_pair(39, 60);
    p[2] = make_pair(5, 28);
    p[3] = make_pair(27, 40);
    p[4] = make_pair(50, 90);

    cout<<maxChain(p)<<endl;
    return 0;
}