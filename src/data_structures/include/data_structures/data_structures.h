#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <cstring>
#include <iostream>

struct Person
{
    public:
        Person(char * name, int age): name(name), age(age) {};
        Person()
        {
            name = nullptr;
            age = 0;
        }

    private:
        char * name;
        int age;
};


#endif