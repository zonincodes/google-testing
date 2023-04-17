#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <cstring>
#include <iostream>

struct Person
{
    public:
        Person(const char * name, int age):age(age) {
            this -> name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        };
        ~Person()
        {
            delete[]name;
        }
        Person()
        {
            name = nullptr;
            age = 0;
        }
    
    const char* getname();

    int getage();

    private:
        char* name;
        int age;
};

void ostreamTest();

#endif