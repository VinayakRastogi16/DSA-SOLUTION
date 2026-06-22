#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>

class Stack{
    public:
        vector<T> vec;
        void push(T val){ //O(1)
            vec.push_back(val);
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty.\n";
                return;
            }
            vec.pop_back();
        }
        T top(){
            // if(isEmpty()){
            //     cout<<"Stack is empty.\n";
            //     return -1;
            // }
            int lastIdx = vec.size()-1;
            return vec[lastIdx];
        }
        bool isEmpty(){
            return vec.size() == 0; 
        }
};

void popAfterHash(string str){
    Stack<char> s;
    Stack<char> t;

    for(char ch:str){
        if(ch == '#'){
            if(!s.isEmpty()){
                char deleted = s.top();
                s.pop();
                t.push(deleted);
            }
        }else if(ch == '+'){
           if(!t.isEmpty()){
             s.push(t.top());
            t.pop();
           }
            
        }else{
            s.push(ch);
        }
    }
    string result;

    while (!s.isEmpty()) {
        result = s.top() + result;
        s.pop();
    }

    cout << "Result: " << result << endl;

}

int main(){
    
    string i;
    cout<<"Enter String\n";
    cin>>i;

    popAfterHash(i);
    return 0;

}