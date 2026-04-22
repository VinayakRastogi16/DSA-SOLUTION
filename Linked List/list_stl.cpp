#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printLL(list<int> ll){
    list<int>::iterator itr;

    for (itr = ll.begin(); itr!= ll.end(); itr++)
    {
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    
    printLL(ll);
    cout<<ll.size()<<endl;
    
    cout<<ll.back()<<endl;
    cout<<ll.front()<<endl;
    // ll.pop_front();
    // ll.pop_back();
    list<int>:: iterator itr = ll.begin();
    advance(itr, 2);

    ll.insert(itr,100,6);
    printLL(ll);

    return 0;
}