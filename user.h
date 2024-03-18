#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class User {
private:
    int id;
    string name;

public:
    User() : id(0), name("") {}

    User(int id, const string& name);

    int getId() const;
    string getName() const;
};

#endif
