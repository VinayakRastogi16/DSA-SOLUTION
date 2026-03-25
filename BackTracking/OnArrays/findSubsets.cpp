#include<iostream>
#include<string>
using namespace std;

void printSubsets(string str, string subset){
    if (str.size() == 0)
    {
        cout<<subset<<"\n";
        return;
    }

    char ch = str[0];

    printSubsets(str.substr(1, str.size()-1), subset+ch); //yes choice
    printSubsets(str.substr(1, str.size()-1), subset); //no choice
    
}


int main(){
    string str = "abc";
    string ans = "";
    printSubsets(str, ans);
    return 0;
}