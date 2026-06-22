#include<iostream>
#include<vector>
using namespace std;

int main(){
   vector<int> arr = {1,5,4};
   int i = 0, j = arr.size()-1;
   int max = 0;
   while(i<j){
      
      if(arr[i]>arr[j]){
         max = arr[i];
         j--;
      }else{
         max = arr[j];
         i++;
      }
   }

   cout<<max<<endl;
   return max;
}