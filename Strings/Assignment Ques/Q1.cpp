#include <iostream>
#include <string>
using namespace std;

void count(string str){
    char arr[5]= {'a','e','i','o','u'};

int count = 0;
    for (int i = 0; i < 5; i++)
    {
        
        for (int j = 0; j < str.length(); j++)
        {
            if (arr[i]==str[j])
            {
                count++;
            }
            
        }
        
    }
    cout<<count<<endl;

}

int countLowercaseVowels(string str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main(){
    string str;
    cout<<"Enter your string"<<endl;
    getline(cin,str);
    cout<<countLowercaseVowels(str)<<endl;
    return 0;
}