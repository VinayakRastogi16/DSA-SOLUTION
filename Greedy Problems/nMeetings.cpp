#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end){
    
    cout<<"selecting activity 0\n";
    int count = 1;
    int currEndTime = end[0];

    for(int i = 1; i< start.size(); i++){
        if(start[i]>=currEndTime){
            cout<<"selecting activity"<<i<<endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}


int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    int x = maxMeetings(start, end);

    cout<<"Max meetings that can be held in One meeting room are "<<x<<endl;

    return 0;
}
