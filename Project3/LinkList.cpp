#include <iostream>

using namespace std;


//Programmer:                               '

//Date:                                  
 //Purpose:  
 


template <class T>
struct node
{
    T info;
    node<T>* next;
    node<T>* prev;
};

template <class T>
class LList
{
private:
    node<T>* first;
    node<T>* last;
    int length;
public:
    //Constructor 
    LList()
    {
        first = NULL;
        last = NULL;
        length = 0;
    }
    // Destructor
    ~LList()
    {
        destroy();
    };
    //Copy constructor
    LList(const LList<T>& other)
    {
        copy(other);
    }
    //Overload the assignment operator 
    const LList<T>& operator= (const LList<T>& other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        return *this;
    }
    //Returns current length of list
    int getLength()
    {
        return length;
    }
   
    bool isEmpty()
    {
        if (first == NULL)
        {
            return true;
        }
        return false;
    }
    // Inserts parameter item
    void insertFront(T item)
    {
        node<T>* new_node = new node<T>();
        new_node->info = item;
        length++;
        if (isEmpty() == true)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            first = new_node;
            last = new_node;
        }
        else {
            new_node->prev = nullptr;
            new_node->next = first;
            first->prev = new_node;
            first = new_node;
        }
    }
    void insertBack(T item)
    {
        node<T>* new_node = new node<T>();
        new_node->info = item;
        length++;
        if (isEmpty() == true)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            first = new_node;
            last = new_node;

        }
        else
        {
            new_node->next = nullptr;
            new_node->prev = last;
            last->next = new_node;
            last = new_node;
        }
    }

    void getlast()
    {
        cout << last;
    }
    void getfirst()
    {
        cout << first;
    }


    void deleteItem(T item)
    {
        node<T>* ptr;
        ptr = first;
        
        if (isEmpty())
        {
            cout << "List is empty";
        }
        else if (first->info == item && first->next != NULL) // there is other items next to the first
        {
            ptr = first;
            first->prev = NULL;
            first = first->next;
            ptr = NULL;
            delete ptr;
            
            length--;
        }
        else if (first->info == item && first->next == NULL) // first is the only item 
        {
            ptr = first;
            first = nullptr;
            ptr = NULL;
            delete ptr;
            length--;
        }
        else if (last->info == item)
        {
            ptr = last;
            last = last->prev;
            last->next = NULL;
            delete ptr;
            
            
            length--;
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                if(ptr->info == item)
                {
                    ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                    ptr = nullptr;
                    
                    delete ptr;
                    length--;
                }
                
            }
        }
       
    }
    

    bool searchItem(T item)
    {
        node<T>* p;
        p = first;

        while (p != NULL && p->info <= item)
        {
            if (item == p->info)
                return true;
            p = p->next;
        }

        return false;
    }
    //Print all items in the list. Print message if list is empty.
    void printList()
    {
        if (isEmpty())
            cout << "\nLIST IS EMPTY\n";
        else
        {
            cout << "\nLIST : \n";

            node<T>* p = first;

            while (p != NULL)
            {
                cout << p->info << " ";
                p = p->next;
            }
        }
    }
    // function to copy a list
    void copy(const LList<T>& other)
    {
        length = other.length;

        if (other.first == NULL)
            first = NULL;
        else
        {
            first = new node<T>;
            first->info = other.first->info;

            node<T>* p = other.first->next;
            node<T>* r = first;
            while (p != NULL)
            {
                r->next = new node<T>;
                r = r->next;
                r->info = p->info;
                p = p->next;
            }
            r->next = NULL;
        }
    }
    // Destroy list function
    void destroy()
    {
        node<T>* p;

        while (first != NULL)
        {
            p = first;
            first = first->next;
            delete p;
        }
    }
    
   
    
    class iterator
    {
    private:
        node<T>* current;
    public:
        iterator()
        {
            current = nullptr;
        }
        iterator(node<T>* n)
        {
            current = n; 
        }
        iterator& operator++()
        {
            current = current->next;
            return *this;
        }
        iterator& operator--()
        {
            current = current->prev;
            return *this;
        }
        iterator& operator*()
        {
            return current->info;
        }
        bool operator==(const iterator& right)const
        {
            return (current == right.current);
        }
        bool operator!=(const iterator& right)const
        {
            return(current != right.current);
        }
    };
    iterator begin()
    {
        return iterator(first);
    }
    iterator end()
    {
        return iterator(last);
    }
    
};

