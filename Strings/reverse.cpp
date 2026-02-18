#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *word, int n){
    int i = 0;
    int j = n-1;

    while(i<j){
        swap(word[i], word[j]);
        i++;
        j--;
    }
    
}


int main(){
    char word[] = "code";

    reverse(word, strlen(word));

    cout<<word<<endl;
    return 0;
}