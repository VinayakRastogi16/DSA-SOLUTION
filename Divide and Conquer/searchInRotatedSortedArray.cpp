#include <iostream>
#include <vector>
using namespace std;

int rotatedSearch(vector<int> &arr, int si, int ei, int key)
{

    if (si > ei)
    {
        return -1;
    }

    int mid = si + (ei - si) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    
    if (arr[si]<=arr[mid])
        {
            if (arr[si]<= key && key<arr[mid])
            {
                return rotatedSearch(arr, si, mid-1, key);
            }else{
                return rotatedSearch(arr, mid+1, ei, key);
            }
            
        }
        else
        {
           if (arr[mid]<key && key <= arr[ei])
           {
            return rotatedSearch(arr, mid+1, ei, key);
           }else{
            return rotatedSearch(arr, si, mid-1, key);
           }
           
        }

}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout<<rotatedSearch(arr, 0, arr.size() - 1, 0)<<endl;

    return 0;
}