#include<iostream>
#include<string>


using namespace std;

void removeDuplicates(string str, string ans, int *map, int i){
    if (i==str.size())
    {
        cout<<"ans : "<<ans<<endl;
        return;
    }

    int mapIdx = (int)(str[i]-'a');


    if (map[mapIdx])
    {
        removeDuplicates(str, ans, map, i+1);
    }else{
        map[mapIdx] = true;
        removeDuplicates(str, ans+str[i], map, i+1);
    }
    

    

}

int main(){
    string str = "appnnacolijklege";
    string ans = "";
    int map[26] = {false};

    removeDuplicates(str, ans, map, 0);

    return 0;
}