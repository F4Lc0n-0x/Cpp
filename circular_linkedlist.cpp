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
    void insert(int new_value)
    {
        Node* newnode = new Node;
        newnode->data = new_value;
        if (isempty())
        {
            newnode->next = newnode;
            head = newnode;
            return;
        }
        Node* tmp = head;
        while(tmp ->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
        newnode->next = head;
    }
    void display()
    {
        if(isempty())
        {
            cout << "List is empty!\n";
            return;
        }
        Node* tmp = head;
        do
        {
            cout << tmp->data <<" ";
            tmp = tmp->next;
        } while(tmp != head);
        cout << endl;
    }
    int count()
    {
        if(isempty())
        {
            return 0;
        }
        Node* tmp = head;
        int items = 0;
        do
        {
            items++;
            tmp = tmp->next;
        } while(tmp != head);
        return items;
    }
    void insert_first(int new_value)
    {
        Node* newnode = new Node;
        newnode->data = new_value;
        if(isempty())
        {
            newnode->next = newnode;
            head = newnode;
            return;
        }
        Node* tmp = head;
        while(tmp->next != head)
        {
            tmp = tmp->next;
        }
        newnode->next = head;
        tmp->next = newnode;
        head = newnode;
    }
    bool finder(int key)
    {
        if(isempty())
        {
            return false;
        }
        Node* tmp = head;
        do
        {
            if(tmp->data == key)
            {
                return true;
            }
            tmp = tmp->next;
        }while(tmp != head);
        return false;
    }
};
int main()
{
    linked_list list;
    int val;
    if (list.isempty())
    {
        cout <<"The list is empty!\n";
    }
    else
    {
        cout <<"List is not empty and has " << list.count() <<" items\n";
    }
    while(1)
    {
        cout << "Enter the value to add (-1 to exit): ";
        cin >> val;
        if (val == -1)
        {
            break;
        }
        list.insert(val);
        list.display();
    }
    while(1)
    {
        cout << "Enter the value to add at first of the list(-1 to exit): ";
        cin >> val;
        if (val == -1)
        {
            list.display();
            break;
        }
        list.insert_first(val);
        list.display();
    }
    cout << "Enter a value to search for it in the list : ";
    cin >> val;
    if(list.finder(val))
    {
        cout<<"The value is found\n";
    }
    else
    {
        cout<<"The value isn't found\n";
    }
}