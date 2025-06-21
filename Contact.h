#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;

public:
    Contact();
    Contact(const string &name, const string &phone, const string &email);

    string getName() const;
    string getPhone() const;
    string getEmail() const;

    void display() const;
};

#endif