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

    ~Node()
    {
        // cout<<"destructor of NODE "<<data<<endl;
        if (next != NULL)
        {

            delete next;
            next = NULL;
        }
    }
};

class List
{
    Node *head;
    Node *tail;

public:
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

    int search(int key)
    {
        Node *temp = head;

        if (tail == head)
        {
            cout << "LL is empty\n";
            return -1;
        }

        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return i;
            }
            else
            {
                temp = temp->next;
                i++;
            }
        }

        return -1;
    }

    int helper(Node *h, int key)
    {

        if (h == NULL)
        {
            return -1;
        }

        if (h->data == key)
        {
            return 0;
        }

        int idx = helper(h->next, key);
        if (idx == -1)
        {
            return -1;
        }

        return idx + 1;
    }

    int searchRec(int key)
    {
        return helper(head, key);
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int getSize(){
        Node* temp = head;
        int size = 0;
        
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }

        return size;
    }

    void removeNth(int n){

        int size = getSize();
        Node* prev = head;


        for (int i = 1; i < (size-n); i++)
        {
            prev = prev->next;
        }

        Node* toDel = prev->next;
        cout<<"Going to delete "<<toDel->data<<endl;
        prev->next = prev->next->next;
        
    }

    bool isPalindrome(){
        Node* h = head;
        if (h == NULL && h->next == NULL)
        {
            return true;
        }

        Node* slow = h;
        Node* fast = h;

        while (fast!=NULL && fast->next!=NULL) // or while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = NULL;
        Node* curr = slow->next;

        while (curr!=NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node* first = h;
        Node* second = prev;

        while (second!=NULL)
        {
            if (first->data != second->data)
            {
                cout<<"Not a palindrome\n";
                return false;
            }

            first = first->next;
            second = second->next;
        }
        
        cout<<"palindrome\n";
        return true;
        
    }

};

int main()
{

    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    ll.isPalindrome();



    // cout << ll.searchRec(4) << endl;



    return 0;
}