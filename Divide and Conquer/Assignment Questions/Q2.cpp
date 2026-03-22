#include <iostream>
#include <vector>
using namespace std;

int countInRange(vector<int> &nums, int num, int si, int ei)
{
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if (nums[i] == num)
            count++;
    }
    return count;
}

int majorityElementRec(vector<int> &nums, int si, int ei)
{
    if (si == ei)
    {
        return nums[si];
    }

    int mid = si + (ei - si) / 2;

    int siMajor = majorityElementRec(nums, si, mid);
    int eiMajor = majorityElementRec(nums, mid + 1, ei);

    if (siMajor == eiMajor){
            return siMajor;
        }

    int siCount = countInRange(nums, siMajor, si, ei);
    int eiCount = countInRange(nums, eiMajor, si, ei);

    return (siCount > eiCount) ? siMajor : eiMajor;
}

int majorityElement(vector<int> &nums)
{
    return majorityElementRec(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 2, 2};
    cout << majorityElement(arr) << endl;
}