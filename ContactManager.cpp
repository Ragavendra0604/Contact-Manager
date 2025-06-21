#include "ContactManager.h"
#include <iostream>
using namespace std;

void ContactManager::addContact(const Contact &contact) {
    auto result = contactsByName.emplace(contact.getName(), contact);
    bool success = result.second;
    auto it = result.first;
    
    if (!success) {
        cout << "Contact with this name already exists!\n";
        return;
    }
    
    contactsByPhone.emplace(contact.getPhone(), &it->second);
    cout << "Contact added successfully!\n";
}

void ContactManager::deleteContact(const string &name) {
    auto it = contactsByName.find(name);
    if (it == contactsByName.end()) {
        cout << "Contact not found!\n";
        return;
    }
    
    contactsByPhone.erase(it->second.getPhone());
    contactsByName.erase(it);
    cout << "Contact deleted successfully!\n";
}

void ContactManager::searchByName(const string &name) {
    auto it = contactsByName.find(name);
    if (it != contactsByName.end()) {
        it->second.display();
    } else {
        cout << "Contact not found!\n";
    }
}

void ContactManager::searchByPhone(const string &phone) {
    auto it = contactsByPhone.find(phone);
    if (it != contactsByPhone.end()) {
        it->second->display();
    } else {
        cout << "Contact not found!\n";
    }
}

void ContactManager::displayAll() {
    if (contactsByName.empty()) {
        cout << "No contacts found!\n";
        return;
    }
    
    cout << "\n--- All Contacts ---\n";
    for (const auto &pair : contactsByName) {
        const Contact &contact = pair.second;
        contact.display();
    }
}