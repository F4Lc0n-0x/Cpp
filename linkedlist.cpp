#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next; 
};
class linked_list
{
public:
    Node* head;
    linked_list()
    {
        head = NULL;
    }
    bool isempty()
    {
        return(head == NULL);
    }
    void insert_first(int new_value) // to add to the list at the first 
    {
        Node* newnode = new Node; // to do a new node to can put at it 
        newnode->data = new_value; // to add the new value to the new node
        if (isempty())
        {
            newnode->next = NULL; // make it null to can add value at it if the list is empty
            head = newnode; // the head will = the new value
        }
        else
        {
            newnode->next = head; // make the next = to the head to can add a new value to the head and be the first value
            head = newnode;
        }
    }
    void display() // for display the list
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
    int count() // for counting items in the list
    {
        int count = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool finder(int key)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insertbefore(int item , int newvalue)
    {
        if(isempty())
        {
            insert_first(newvalue);
        }
        if(finder(item))
        {
            Node *tmp = head;
            Node *newnode = new Node;
            newnode->data = newvalue;
            while(tmp->next->data != item && tmp != NULL)
            {
                tmp = tmp->next;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
        }
        else
        {
            cout <<"Item is not found!\n";
        }
    }
    void append(int newvalue)
    {
        if(isempty())
        {
            insert_first(newvalue);
        }
        else
        {
            Node *tmp = head;
            Node *newnode = new Node;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            newnode->data = newvalue;
            tmp->next = newnode;
            newnode->next = NULL;
        }
    }
    void rmv(int value)
    {
        if(isempty())
        {
            cout<<"List is empty, no items to remove!\n";
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        if(head ->data == value)
        {
            head = head->next;
            delete curr;
            return;
        }
        while(curr != NULL && curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout <<"Value not found!\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
};
int main()
{
    linked_list list;
    int val;
    int item;
    if (list.isempty())
    {
        cout << "The list is EMPTY!\n";
    }
    else
    {
        cout << "List isn't empty and has " << list.count() << "items\n";
    }
    while(val != -1)
    {
        cout << "Enter the value you need to add to the list (-1 for exit) : ";
        cin >> val;
        if(val == -1)
        {
            break;   //for break if the user need to exit without add the -1 to the list
        }
        list.insert_first(val);
        list.display();
    }
    /*
    ---------- Testing ----------
    cout << "Enter the value you need to add to the list : ";
    cin >> val;
    list.insert_first(val);
    list.display();
    cout << "Enter the value you need to add to the list : ";
    cin >> val;
    list.insert_first(val);
    list.display();
    ---------- Testing ----------
    */
    cout << "List has " << list.count() << " items\n";
    cout << "Enter the value you need to search in the list : ";
    cin >> val;
    if(list.finder(val))
    {
        cout << "The item is found!\n";
    }
    else
    {
        cout << "The item isn't in the list!\n";
    }
    cout << "Enter Item you need to add before : ";
    cin >> item;
    cout << "Enter value you need to add before the item chosen : ";
    cin >> val;
    list.insertbefore(item,val);
    list.display();
    cout << "Enter the value you need to add at last of the list : ";
    cin >> val;
    list.append(val);
    list.display();
    cout << "Enter the value you need remove from the list : ";
    cin >> val;
    list.rmv(val);
    list.display();
}