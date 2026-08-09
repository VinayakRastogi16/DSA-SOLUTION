#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> removeZero(vector<int>& arr){
    int i = 0;
    int j = 1;

    while(j < arr.size()){
        if(arr[i] == 0 && arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
            if(i == j) j++;
        }
        else if(arr[i] != 0){
            i++;
            if(i == j) j++;
        }
        else{
            j++;
        }
    }
    return arr;
}
int main(){
    vector<int> arr = {4,2,4,0,0,3,0,5,1,0};
    removeZero(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}