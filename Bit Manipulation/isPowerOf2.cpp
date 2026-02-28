#include <iostream>

using namespace std;

bool isPowerOf2(int num){
    if ((num&(num-1))== 0)
    {
        return true;

    }else{
        return false;
    }
    
}

int main(){

    cout<<isPowerOf2(4)<<endl;
    return 0;
}