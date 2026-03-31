#include<iostream>
#include<string>
#include<vector>
using namespace std;

string mapping[]={"", "", "abc", "def", "ghi", "jkl", "mno", "'qrs", "tuv", "wxyz"};

void solve(string digits, int idx, string current){
    if (idx == digits.size())
    {
        cout<<current<<" ";
        return;
    }

    string letters = mapping[digits[idx]- '0'];

    for (int i = 0; i < letters.size(); i++)
    {
        solve(digits, idx+1, current+letters[i]);
    }
    
    
}

int main(){

    string digits;
    cin>>digits;

    if (digits.size()==0)
    {
        return 0;
    }

    solve(digits, 0, "");

    return 0;
    
    
}