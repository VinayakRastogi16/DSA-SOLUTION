#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
public:
    int cnt;
    int idx;

    Row(int cnt, int idx){
        this->cnt = cnt;
        this->idx = idx;
    }

    bool operator < (const Row& obj) const{
        if(this->cnt==obj.cnt){
            return this->idx>obj.idx;
        }
        return this->cnt > obj.cnt;
    }
};

void weakestSoldier(vector<vector<int>>& mat, int k){
    vector<Row> rows;

    for(int i = 0; i<mat.size(); i++){
        int cnt =0;
        for(int j = 0; j<mat[i].size() && mat[i][j]==1; j++){
            cnt++;
        }
        rows.push_back(Row(cnt, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i = 0; i<k; i++){
        cout<<"Row" << pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<vector<int>> mat =  {{1,0,0,0},
                                {1,1,1,1},
                                {1,0,0,0},
                                {1,0,0,0}};

    weakestSoldier(mat, 2);

    return 0;
}