#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBttm(stack<int> &s, int val){

    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBttm(s, val);
    s.push(temp);
}

string reverseString(string str){
    string ans;
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
    
}

int main(){

    // stack<int> s;
    // s.push(3);
    // s.push(2);
    // s.push(1);

    // pushAtBttm(s, 4);

    // while (!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;

    string str = "abcd";
    cout<<"Reverse = "<<reverseString(str)<<endl;
    
    return 0;
}