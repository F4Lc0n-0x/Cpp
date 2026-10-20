#include <iostream>
using namespace std;
class Array 
{
private:
    int size;
    int lenght;
    int *items;
public:
    Array(int arrsize)
    {
        size = arrsize;
        lenght = 0;
        items = new int[arrsize];
    }
    void fill()
    {
        int no_of_items;
        cout << "How many items you need to fill : ";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cout <<"You cannot exceed the array size\n";
            return;
        }
        else
        {
            for (int i =0; i<no_of_items; i++)
            {
                cout <<"Enter the item no " << i+1<<" : ";
                cin >> items[i];
                lenght ++;
            }
        }
    }
    void display()
    {
        cout <<"Array content\n";
        for (int i =0; i<lenght; i++)
        {
            cout <<items[i]<<"\t";
        }
        cout <<endl;
    }
    int getsize()
    {
        return size;
    }
    int getlength()
    {
        return lenght;
    }
    int search(int key)
    {
        int index = -1;
        for(int i =0; i < lenght; i++)
        {
            if (items[i] == key)
            {
                index = i;
            }
        }
        return index;
    }
    void append(int new_num)
    {
        if (lenght < size)
        {
            items[lenght] = new_num;
            lenght++;
        }
        else
        {
            cout << "We don't have space in the array to add!\n";
        }
    }
    void insert(int user_index , int add)
    {
        if (user_index >= 0 && user_index < size)
        {
            for (int i = lenght; i > user_index; i--)
            {
                items[i] = items[i-1];
            }
            items[user_index] = add;
            lenght++;
        }
        else
        {
            cout << "Error index out of range!\n";
        } 
    }
    void deleting(int rm_index)
    {
        if (rm_index >= 0 && rm_index < size)
        {
            for(int i = rm_index; i < lenght-1; i++)
            {
                items[i] = items[i+1];
            }
            lenght--;
        }
        else 
        {
            cout << "Index not in the array!\n";
        }
    }
    void enlarge(int new_size)
    {
        if (new_size <= size)
        {
            cout <<"The new size must be larger that old size!\n";
            return;
        }
        else 
        {
            size = new_size;
            int *old = items;
            items = new int[new_size];
            for (int i =0; i < lenght; i++)
            {
                items[i] = old[i];
            }
            delete[]old;
        }
    }
    void merge(Array other)
    {
        int new_size = size + other.getsize();
        size = new_size;
        int *old = items;
        items = new int[new_size];
        int i;
        for (i = 0; i < lenght; i++)
        {
            items[i] = old[i];
        }
        delete[]old;
        int j=i;
        for(int i =0; i < other.getlength(); i++)
        {
            items[j++] = other.items[i];
            lenght++;
        }
    }
};
int main()
{
    cout<<"Welcome to my program\n";
    int arrsize;
    cout<<"Enter the array size : ";
    cin >> arrsize;
    Array myarray(arrsize);
    myarray.fill();
    myarray.display();
    cout <<"Array size : " << myarray.getsize() << " And array length is : " << myarray.getlength() <<endl;
    int key;
    cout << "Enter the number you need to find :  ";
    cin >> key;
    int index = myarray.search(key);
    if (index == -1)
    {
        cout<<"Number not found!\n";
    }
    else
    {
        cout << "Item found at index " << index <<endl;
    }
    int new_num;
    cout <<"Enter the numebr you need to add : ";
    cin >> new_num;
    myarray.append(new_num);
    myarray.display();
    int usr_indx , add , remove;
    cout << "Enter the index you need to add in it : ";
    cin >> usr_indx;
    cout << "Enter the number you need to insert : ";
    cin >> add;
    myarray.insert(usr_indx,add);
    myarray.display();
    cout << "Enter the index you need to remove number from it : ";
    cin >> usr_indx;
    myarray.deleting(usr_indx);
    myarray.display();
    int new_size;
    cout << "Enter the new size : ";
    cin >> new_size;
    myarray.enlarge(new_size);
    cout <<"Array size : " << myarray.getsize() << " And array length is : " << myarray.getlength() <<endl;
    myarray.display();
    Array other(3);
    other.fill();
    myarray.merge(other);
    cout <<"Array size : " << myarray.getsize() << " And array length is : " << myarray.getlength() <<endl;
    myarray.display();
}