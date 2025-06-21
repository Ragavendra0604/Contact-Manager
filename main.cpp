#include "ContactManager.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>
using namespace std;

void displayMenu() {
    cout << "\n--- Contact Manager ---\n"
         << "1. Add Contact\n"
         << "2. Delete Contact\n"
         << "3. Search by Name\n"
         << "4. Search by Phone\n"
         << "5. Display All Contacts\n"
         << "6. Exit\n"
         << "Enter your choice: ";
}

int main() {
    ContactManager manager;
    const string filename = "contacts.txt";

    // Load contacts
    auto loadedContacts = FileHandler::loadFromFile(filename);
    for (const auto &pair : loadedContacts) {
        const Contact &contact = pair.second;
        manager.addContact(contact);
    }

    int choice;
    string name, phone, email;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "\nEnter Name: ";
                getline(cin, name);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Email: ";
                getline(cin, email);
                manager.addContact(Contact(name, phone, email));
                break;

            case 2:
                cout << "\nEnter Name to Delete: ";
                getline(cin, name);
                manager.deleteContact(name);
                break;

            case 3:
                cout << "\nEnter Name to Search: ";
                getline(cin, name);
                manager.searchByName(name);
                break;

            case 4:
                cout << "\nEnter Phone to Search: ";
                getline(cin, phone);
                manager.searchByPhone(phone);
                break;

            case 5:
                manager.displayAll();
                break;

            case 6:
                FileHandler::saveToFile(manager.getContacts(), filename);
                cout << "\nContacts saved. Exiting...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}