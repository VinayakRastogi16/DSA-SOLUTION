#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string>& mp){
    unordered_set<string> to;

    for(pair<string, string> tkt: mp){
        to.insert(tkt.second);
    }

    string st = "";

    for(pair<string, string> t : mp){
        if(to.find(t.first)== to.end()){
            st = t.first;
        }
    }

    cout<<st<<" -> ";
    while(mp.count(st)){
        cout<<mp[st]<<" -> ";
        st = mp[st];
    }

    cout<<"Destination reached!!"<<endl;
}

int main(){
    unordered_map<string, string> mp;

    mp["Chennai"] = "Bengaluru";
    mp["Mumbai"] = "Delhi";
    mp["Goa"] = "Chennai";
    mp["Delhi"] = "Goa";

    printItinerary(mp);

    return 0;

}