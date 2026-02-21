#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec1={1,2,3,4,5};
    cout<<vec1.size()<<"\n";
    cout<<vec1.capacity()<<"\n";
    vec1.push_back(11);
    cout<<vec1.size()<<"\n";
    cout<<vec1.capacity()<<"\n";
    return 0;
}