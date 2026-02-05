#include <iostream>
using namespace std;

int main(){
    int x =5 , y = 10;
     
    int *ptr = &x;
    int *ptr2 = &y;
    ptr2 = ptr;


    cout<<ptr2<<"=" << ptr<<"\n";
    return 0;
}