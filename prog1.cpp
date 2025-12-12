#include <iostream>
using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;
    int quantity;

public:
    void inputdetails()
    {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Due Date: ";
        cin >> dueDate;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    virtual void checkOut()
    {
        cout << "Item checked out.\n";
    }

    virtual void returnItem()
    {
        cout << "Item returned.\n";
    }

    virtual void displayDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class Book : public LibraryItem
{
public:
    void displayDetails()
    {
        cout << "Item Type: Book\n";
        LibraryItem::displayDetails();
    }
};

class DVD : public LibraryItem
{
public:
    void displayDetails()
    {
        cout << "Item Type: DVD\n";
        LibraryItem::displayDetails();
    }
};

class Magazine : public LibraryItem
{
public:
    void displayDetails()
    {
        cout << "Item Type: Magazine\n";
        LibraryItem::displayDetails();
    }
};

int main()
{
    LibraryItem* items[10];
    int count = 0;
    int choice;

    do
    {
        cout << "\n---- Library Menu ----\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Show All Items\n";
        cout << "5. Check Out Items\n";
        cout << "6. Return Items\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            if (count == 10)
            {
                cout << "Library is full!\n";
                continue;
            }
            if (choice == 1)
            {
                items[count] = new Book();
            }
            else if (choice == 2)
            {
                items[count] = new DVD();
            }
            else
            {
            items[count] = new Magazine();
            }
            items[count]->inputdetails();
            count++;
            cout << "Item added.\n";
        }

        else if (choice == 4)
        {
            if (count == 0)
                cout << "No items available.\n";
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "\n------------------\n";
                    items[i]->displayDetails();
                }
            }
        }

        else if (choice == 5)
        {
            int i;
            cout << "Enter item number (0-" << count - 1 << "): ";
            cin >> i;
            if (i >= 0 && i < count)
                items[i]->checkOut();
            else
                cout << "Invalid.\n";
        }

        else if (choice == 6)
        {
            int i;
            cout << "Enter item number (0-" << count - 1 << "): ";
            cin >> i;
            if (i >= 0 && i < count)
                items[i]->returnItem();
            else
                cout << "Invalid.\n";
        }

    } while (choice != 7);

    for (int i = 0; i < count; i++)
        delete items[i];

    cout << "\n-----------------------\n";
    cout << "Exiting the program\n";
    cout << "-----------------------\n";
    return 0;
}