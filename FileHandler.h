#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Contact.h"
#include <map>
#include <string>
using namespace std;

class FileHandler {
public:
    static void saveToFile(const map<string, Contact> &contacts, const string &filename);
    static map<string, Contact> loadFromFile(const string &filename);
};

#endif