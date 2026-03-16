#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int> &arr, int st, int end, int key)
{
    if (st > end)
    {
        return -1;
    }

    int mid = (st + end) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return binSearch(arr, st, mid - 1, key);
    }
    else
    {
        return binSearch(arr, mid + 1, end, key);
    }

}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << binSearch(arr, 0, arr.size() - 1, 7) << endl;

    return 0;
}
