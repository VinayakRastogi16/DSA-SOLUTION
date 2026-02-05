#include<iostream>
using namespace std;



int LinearSearch(int arr[], int key, int n){
    for (int j = 0; j< n; j++)
    {
        if (arr[j] == key){
            return j;
        }
            
        
    }
    return -1;
}


int main(){

     int n;
     
     

     cout<<"Enter the size of array";
     cin>> n ;

     int arr[n];

     cout<<"Enter the elements \n";

     for(int i=0;i<n;i++){
        
        cin>>arr[i];
     }

     

     

     cout<<LinearSearch(arr, 10, n)<<endl;

    return 0; 
}   