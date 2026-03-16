#include<iostream>
#include<string>
#include<vector>
using namespace std;

void sameStartEnd(string str ,int i, int end, vector<string> &ans){
    if (i >= str.length())
    {
        return;
    }

    if (end > str.length())
    {
        sameStartEnd(str, i+1 , i+1, ans);
        return;
    }
    
    

    if (str[i]==str[end-1])
    {
        string slice = str.substr(i,end-i);
        ans.push_back(slice);
    }

    sameStartEnd(str, i, end+1, ans);
    

}

int main(){

    string str = "abcab";
    vector<string> ans;

    sameStartEnd(str, 0, 1, ans);   // FIXED

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}