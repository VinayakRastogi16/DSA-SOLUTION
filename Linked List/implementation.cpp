#include<iostream>
using namespace std;

class Node{
    
public:
    int data;
    Node* next;


    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        // cout<<"destructor of NODE "<<data<<endl;
        if (next!=NULL)
        {
            
            delete next;
            next = NULL;
        }
        
    }

};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;

    }

   
    ~List(){

        //  cout<<"destructor list\n";
        if (head!=NULL)
        {
            delete head;
            head = NULL;
        }
        
    }

    void printList(){

        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;

    }

    void push_front(int val){
        Node* newNode = new Node(val); //dynamic allocation 

        if(head==NULL){
            head = tail = newNode;

        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val); //dynamic allocation 

        if(head==NULL){
            head = tail = newNode;

        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        
    }

    void pop_front(){

        if (head == NULL)
        {
            cout<<"LL is empty\n";
            return;
        }
        

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
        
        
    }
    void pop_back(){
        Node* temp = head;

        if (tail == head)
        {
            cout<<"LL is empty\n";
            return;
        }
        
        

        while(temp->next->next !=NULL){//or temp->next->next !=NULL
            temp=temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
        
        
        
    }

    int search(int key){
        Node* temp = head;

        if (tail == head)
        {
            cout<<"LL is empty\n";
            return -1;
        }

        int i = 0;
        while (temp!=NULL)
        {
            if (temp->data==key)
            {
                return i;
            }else{
                temp= temp->next;
                i++;
            }
            
        }   
        
        return -1;

    }

    int helper(Node* h, int key){

        if (h == NULL)
        {
            return -1;
        }
        

        if(h->data == key){
            return 0;
        }

        int idx = helper(h->next, key);
        if (idx==-1)
        {
            return -1;
        }

        return idx+1;
        
    }

    int searchRec(int key){
        return helper(head, key);
    }
};


int main(){

    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printList();

    // ll.pop_back();
    // ll.printList();
    // ll.pop_back();
    // ll.printList();
    // ll.pop_back();

    cout<<ll.searchRec(4)<<endl;
    return 0;
}