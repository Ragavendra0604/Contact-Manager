#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "Contact.h"
#include <map>
#include <unordered_map>
using namespace std;

class ContactManager {
private:
    map<string, Contact> contactsByName;          // O(log n) operations
    unordered_map<string, Contact*> contactsByPhone; // O(1) average case

public:
    void addContact(const Contact &contact);    // O(log n)
    void deleteContact(const string &name);     // O(log n)
    void searchByName(const string &name);      // O(log n)
    void searchByPhone(const string &phone);    // O(1)
    void displayAll();                          // O(n)
    
    const map<string, Contact>& getContacts() const { return contactsByName; }
};

#endif