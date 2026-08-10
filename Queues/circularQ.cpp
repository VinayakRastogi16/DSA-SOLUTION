#include<iostream>
using namespace std;

class Queue{
    int* arr;

    int capacity;
    int currSize;

    int f, r;

    public:
        Queue(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            currSize = 0;
            f = 0;
            r = -1;
        }

        void push(int data){

            if(currSize == capacity){
                cout<<"Queue is full\n";

                return;
            }

            r = (r+1)%capacity;
            arr[r] = data;
            currSize++;

        }

        void pop(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return;
            }
            f = (f+1)% capacity;
            currSize--;
        }

        int front(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return arr[f];
        }

        bool isEmpty(){
            return currSize == 0;

        }
};

int main(){
    Queue q(4);

    q.push(1);
    q.push(4);
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}