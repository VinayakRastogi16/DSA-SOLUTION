#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool isDuplicate(string str){
    stack<char> s;

    for(char ch : str){

        if(ch != ')'){
            s.push(ch);
        }else{
            if(s.top()=='('){
                return true;
            }

            while(s.top() != '('){
                s.pop();
            }
            s.pop();
        }
    }

    return false;

}

int main(){
    string str = "((a+b)+(c+d))";
    bool ans = isDuplicate(str);
    cout<<ans<<endl;
    return 0;
}