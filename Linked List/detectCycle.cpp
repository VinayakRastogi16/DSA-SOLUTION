#include <iostream>
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
};

void printList(Node* head)
    {

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout<<"Cycle exists\n";
            return true;
        }
        
    }

    cout<<"No cycle detected\n";
    return false;
    
}


int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;

    isCycle(ll.head);
    return 0;
}