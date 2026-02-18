#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string str, string str2)
{

    if (str.length() != str2.length())
    {
        cout << "Not an anagram\n";
        return false;
    }

    int freq[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        int idx = str[i] - 'a';
        freq[idx]++;
    }

    for (int i = 0; i < str2.length(); i++)
    {
        int idx = str2[i] - 'a';
        if (freq[idx] == 0)
        {
            cout << "Not an anagram\n";
            return false;
        }
        freq[idx]--;
    }
    cout << "Valid anagram\n";
    return true;
}

int main()
{
    string str = "ranagam";
    string str2 = "nagaram";
    isAnagram(str, str2);

    return 0;
}