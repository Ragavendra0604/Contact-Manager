#include "FileHandler.h"
#include <fstream>
#include <sstream>
using namespace std;

void FileHandler::saveToFile(const map<string, Contact> &contacts, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &pair : contacts) {
            const Contact &contact = pair.second;
            file << contact.getName() << ","
                << contact.getPhone() << ","
                << contact.getEmail() << "\n";
        }
        file.close();
    }
}

map<string, Contact> FileHandler::loadFromFile(const string &filename) {
    map<string, Contact> contacts;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone, email;
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            contacts.emplace(name, Contact(name, phone, email));
        }
        file.close();
    }
    return contacts;
}