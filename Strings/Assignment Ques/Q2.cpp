#include <iostream>
#include <string>

using namespace std;

bool equalWithOneSwap(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    int first = -1;
    int second = -1;
    int misMatch = 0;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            misMatch++;

            if (misMatch == 1)
            {
                first = i;
            }
            else if (misMatch == 2)
            {
                second = i;
            }
            else
            {
                return false;
            }
        }
    }

    if (misMatch == 0)
    {
        return true;
    }

    if (misMatch == 2)
    {
        cout<<"true\n";
        return (s1[first] == s1[second] && s1[second] == s2[first]);
    }

    return false;
}

bool canMakeEqualWithOneSwap(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int first = -1;
    int second = -1;
    int mismatchCount = 0;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            mismatchCount++;

            if (mismatchCount == 1)
            {
                first = i;
            }
            else if (mismatchCount == 2)
            {
                second = i;
            }
            else
            {
                return false; // more than 2 mismatches
            }
        }
    }

    // Case 1: already equal
    if (mismatchCount == 0)
        return true;

    // Case 2: exactly two mismatches
    if (mismatchCount == 2)
    {
        return (s1[first] == s2[second] &&
                s1[second] == s2[first]);
    }

    // Case 3: exactly one mismatch
    return false;
}

int main()
{
    string s1 = "Dhlei";
    string s2 = "Delhi";

    cout << equalWithOneSwap(s1, s2);
    return 0;
}