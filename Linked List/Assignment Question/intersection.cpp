#include<iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

};

class List
{
    
public:

    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {

        //  cout<<"destructor list\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void printList()
    {

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic allocation

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val); // dynamic allocation

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {

        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        Node *temp = head;

        if (tail == head)
        {
            cout << "LL is empty\n";
            return;
        }

        while (temp->next->next != NULL)
        { // or temp->next->next !=NULL
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }



};

Node* intersection(Node* h1, Node* h2){
    Node* i = h1;
    Node* j = h2;

    while(i!=j){
        
        if (i == NULL)
        {
            i = h2;
        }else{
            i = i->next;
        }

        if (j==NULL)
        {
            j = h1;
        }else{
            j = j->next;
        }
        
        
    }

    return i;
}

int main(){

    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(6);
    ll.push_back(7);

    List ll2;

    ll2.push_back(4);
    ll2.push_back(5);

    ll2.tail->next = ll.head->next->next->next;

    Node* inter = intersection(ll.head, ll2.head);

    if(inter != NULL)
        cout << "Intersection at node: " << inter->data << endl;
    else
        cout << "No intersection" << endl;


    cout<<inter<<endl;

    return 0;

}