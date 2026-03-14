#include<iostream>
#include<fstream>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
};

void addContact()
{
    Contact c;
    ofstream file("contacts.txt", ios::app);

    cout<<"Enter Name: ";
    cin>>c.name;

    cout<<"Enter Phone: ";
    cin>>c.phone;

    file<<c.name<<" "<<c.phone<<endl;
    file.close();

    cout<<"Contact Saved Successfully\n";
}

void viewContacts()
{
    Contact c;
    ifstream file("contacts.txt");

    cout<<"\n--- Contact List ---\n";

    while(file>>c.name>>c.phone)
    {
        cout<<"Name: "<<c.name<<"  Phone: "<<c.phone<<endl;
    }

    file.close();
}

void searchContact()
{
    Contact c;
    string name;
    bool found=false;

    ifstream file("contacts.txt");

    cout<<"Enter name to search: ";
    cin>>name;

    while(file>>c.name>>c.phone)
    {
        if(c.name==name)
        {
            cout<<"Contact Found\n";
            cout<<"Name: "<<c.name<<endl;
            cout<<"Phone: "<<c.phone<<endl;
            found=true;
        }
    }

    if(!found)
        cout<<"Contact Not Found\n";

    file.close();
}

int main()
{
    int choice;

    while(true)
    {
        cout<<"\nCONTACT MANAGEMENT SYSTEM\n";
        cout<<"1. Add Contact\n";
        cout<<"2. View Contacts\n";
        cout<<"3. Search Contact\n";
        cout<<"4. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                viewContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid choice\n";
        }
    }
}