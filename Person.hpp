#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H
class Person{
    private:
        std::string first_name_;
        std::string last_name_;
        std::string school_;
        std::string field_;
    public:
        Person(std::string first_name, std::string last_name, std::string school, std::string field);
};
#endif