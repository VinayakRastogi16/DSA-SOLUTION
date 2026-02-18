#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char *word, int n){

    int i = 0, j = n-1;

    while (i<j)
    {
        if(word[i++] != word[j--]){
            cout<<"Not a valid palindrome\n";
            return false;
        }
    }
    
    cout<<"Valid Palindrome \n";
    return true;

}


int main(){
    char word[]= "racecar";

    isPalindrome(word, strlen(word));


    return 0;
}