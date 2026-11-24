#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Stack
{
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }
    bool isempty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int value)
    {
        Node *newnode = new Node;
        newnode->data = value;
        if(isempty())
        {
            newnode->next = NULL;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    void display()
    {
        Node *tmp = top;
        while(tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    int count()
    {
        int total = 0;
        Node *tmp = top;
        while(tmp != NULL)
        {
            total++;
            tmp = tmp->next;
        }
        return total;
    }
    int pop()
    {
        if(isempty())
        {
            return -1;
        }
        int value;
        Node *del = top;
        value = top->data;
        top = top->next;
        delete del;
        return value;
    }
    int peek()
    {
        if(isempty())
        {
            return -1;
        }
        return top->data;
    }
    bool isfound(int value)
    {
        Node *tmp = top;
        while (tmp != NULL)
        {
            if(tmp->data == value)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
    ~Stack()
    {
        while(!isempty())
        {
            pop();
        }
    }
};
int main()
{
    int new_value;
    Stack s;
    int answer;
    if(s.isempty())
    {
        cout<< "The Stack is empty!\n";
    }
    else
    {
        cout << "The Stack isn't empty and has " << s.count() << " items!\n";
    }
    do
    {
        cout << "(-1)-To quit\n1- Add an item to the Stack\n2- Remove the first item from the Stack\n3- To print the value at the top\n4- Search for a value in the Stack\n";
        cout << "Your choise : ";
        cin >> answer;
        if(answer == 1)
        {
            while(1)
            {
                cout << "Enter a value to add (-1 to quit) : ";
                cin >> new_value;
                if(new_value == -1)
                {
                    s.display();
                    break;
                }
                s.push(new_value);
                s.display();
            }
        }
        else if(answer == -1)
        {
            s.display();
            break;
        }
        else if(answer == 2)
        {
            if(s.isempty())
            {
                cout <<"The Stack is empty!\n";
            }
            else
            {
                int del = s.pop();
                cout << "The value "<<del <<" has been removed from the Stack\n";
                s.display();
            }
        }
        else if(answer == 3)
        {
            if(s.isempty())
            {
                cout <<"The Stack is empty!\n";
            }
            else
            {
                cout << "The top value at the Stack is : "<<s.peek()<<endl;
            }
        }
        else if(answer == 4)
        {
            cout << "Enter the value need to search on it in the Stack : ";
            cin >> new_value;
            if(s.isfound(new_value))
            {
                cout <<"The value has been found!\n";
            }
            else
            {
                cout <<"The value hasn't found!\n";
            }
        }
    }while(answer != -1);
    cout << "The Stack has " << s.count() << " items\n";
}