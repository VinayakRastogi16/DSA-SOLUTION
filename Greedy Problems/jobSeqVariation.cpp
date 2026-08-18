#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Job{
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->deadline = deadline;
        this->idx = idx;
        this->profit = profit;
    }
};

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second>p2.second;
}

int maxProfit(vector<pair<int, int>>& p){

    vector<Job> jobs;
    int n = p.size();
    
    for(int i = 0; i<n; i++){
        jobs.emplace_back(i, p[i].first, p[i].second);
    }
    
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b){
        return a.profit>b.profit;
    });

    cout<<"Selecting Job "<<jobs[0].idx<<endl;
    int ans = jobs[0].profit;
    int safeDeadLine = 2;

    for(int  i =1; i < n; i++){
        if(jobs[i].deadline>=safeDeadLine){
            cout<<"Selecting Job "<<jobs[i].idx<<endl;
            ans += jobs[i].profit;
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