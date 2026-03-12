#include <iostream>
#include <vector>

using namespace std;

int lastOccurence(vector<int> &arr, int i, int target)
{
    if (i < 0)
    {
        return -1;
    }

    if (arr[i] == target)
    {
        return i;
    }

    return lastOccurence(arr, i - 1, target);
}

int lastOccurence2(vector<int> arr, int i, int target)
{
    if (i == arr.size())
    {
        return -1;
    }

    int idxFound = lastOccurence2(arr, i + 1, target);

    if (idxFound == -1 && arr[i] == target)
    {
        return i;
    }

    return idxFound;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4};
    cout << lastOccurence(arr, arr.size()-1, 3) << endl;

    return 0;
}