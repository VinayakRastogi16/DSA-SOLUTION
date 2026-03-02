#include<iostream>
#include<string>
using namespace std;


class User{
    int id;
    string pass;

    public:
    string username;

    User(int id){
        (*this).id = id;
    }

    void setPassword(string pass){
        this->pass = pass;
    }

    string getPassword(){
        return pass;
    }

};

int main(){

    User user1(101);
    user1.username = "Vinayak";
    user1.setPassword("Vinayak@18");
    cout<<user1.getPassword()<<endl;
    return 0;

}