#include "LinkList.cpp"


/***************************************************************/
/* Programmer:                                                 */        /* Date:                                                       */
/* Purpose: Test linked list class using a menu driven         */
/*          program                                            */
/* Input: user’s choice to perform an operation                */        /* Output: menu of choices and results of user’s operations.   */        /***************************************************************/

// printMenu displays a menu of choices and returns the user's choice

int printMenu();

// InsertList inserts an item into the list parameter

void front(LList<int>&);

void back(LList<int>&);

// deleteList deletes an item from the list parameter

void deleteListItem(LList<int>&);

// searchItem searches for an item in the list parameter

void searchListItem(LList<int>);

//************************** main program ************************/
void iteratefromtheback(LList<int>&);


void iteratefromthefront(LList<int>&);

int main()
{
    LList<int> l;
    int choice;

    cout << "\nOperations allowed on the unsorted list of integers are below."
        << "\nPlease enter the number of your choice and press return.\n\n";

    choice = printMenu();





    while (choice != 7)
    {

        switch (choice)
        {

        case 1:front(l);
            break;

        case 2:back(l);
            break;

        case 3: deleteListItem(l);
            break;

        case 4: l.printList();
            break;

        case 5: searchListItem(l);
            break;

        case 6: cout << "\nThe list contains " << l.getLength()
            << " items\n\n";
            break;

        default:cout << "\nNumber is not correct. Please look at "
            << "choices and reenter\n\n";
            break;
        }

        choice = printMenu();
    }

    
}

int printMenu()
{
    int c;

    cout << "\n1: Add an item to the front.";
    cout << "\n2: Add an item to the back";
    cout << "\n3: Delete an item from the list.";
    cout << "\n4: Print the list.";
    cout << "\n5: Search the list for a given item";
    cout << "\n6: Return the number of items in the list";
    cout << "\n7: Quit.\n\n";
    cin >> c;

    return c;
}
void front(LList<int> &l)
{
    int num;
    cout << "\n Enter the number to insert: ";
    cin >> num;
    l.insertFront(num);
    cout << "\n the number has been inserted\n";
}
void back(LList<int> &l)
{
    int num;
    cout << "\nEnter the number to insert : ";
    cin >> num;
    l.insertBack(num);
    cout << "\nThe number has been inserted\n";
}

void deleteListItem(LList<int>& l)
{

    int num;
    cout << "\nEnter the number to delete : ";
    cin >> num;
    l.deleteItem(num);
    cout << "\nThe number has been deleted\n";;
    l.getlast();
}

void searchListItem(LList<int> l)
{
    int num;
    cout << "\nEnter the number to search for : ";
    cin >> num;
    if (l.searchItem(num))
          cout << "\nThe number is in the list\n\n";
    else  cout << "\nThe number is NOT in the list\n\n";

}
void iteratefromtheback(LList<int>l,LList<int>::iterator x)
{
    for (auto x = l.begin(); x != l.end(); x++)
    {
        cout << *x;
    }
}
void iteratefromthefront(LList<int>l, LList<int>::iterator x)
{
    for (auto x = l.end(); x != l.begin(); x++)
    {
        cout << *x; 
    }
}
