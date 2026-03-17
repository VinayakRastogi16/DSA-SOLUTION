#include<iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest){

    if (n==1)
    {
        cout<<"Shift Disk 1 form "<<src<<" to "<<dest<<endl;
        return;
    }

    towerOfHanoi(n-1, src, dest, helper);

    cout<<"Move Disk "<< n <<" from "<< src <<" to "<<dest<<endl;
    
    
    towerOfHanoi(n-1, helper, src, dest);
    

}

int main(){
    int n =4;
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}