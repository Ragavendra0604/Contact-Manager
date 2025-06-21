#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() : name(""), phone(""), email("") {}

Contact::Contact(const string &name, const string &phone, const string &email)
    : name(name), phone(phone), email(email) {}

string Contact::getName() const { return name; }
string Contact::getPhone() const { return phone; }
string Contact::getEmail() const { return email; }

void Contact::display() const {
    cout << "\nName: " << name << "\nPhone: " << phone << "\nEmail: " << email << "\n";
}