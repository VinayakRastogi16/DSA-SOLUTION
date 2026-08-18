#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second>p2.second;
}

int maxProfit(vector<pair<int, int>>& p){
    int n = p.size();
    sort(p.begin(), p.end(), compare);

    int ans = p[0].second;
    int safeDeadLine = 2;

    for(int  i =1; i < n; i++){
        if(p[i].first>=safeDeadLine){
            ans += p[i].second;
            safeDeadLine++;
        }
    }
    return ans;
}

int main(){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout<<maxProfit(jobs)<<endl;
    return 0;
}