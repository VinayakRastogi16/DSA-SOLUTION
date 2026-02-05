#include <iostream>
using namespace std;


int binSearch(int *arr, int n, int key){
    int st = 0;
    int end = n-1;

    

    while(st<=end){
        int mid = (st+end)/2;

        if(key == arr[mid]){
            return mid;
        }
        else if (key > arr[mid]){
            st = mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    
    return -1;

}




int main(){

    int arr[] = {2,3,4,34,45,64,232,343,545};
    int n = sizeof(arr)/sizeof(int);


    cout<<binSearch(arr, n, 232)<<endl;


    return 0;

}