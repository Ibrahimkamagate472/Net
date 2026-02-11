#include <iostream>
#include <string>
#include <unordered_map>

#ifndef PERSON_H
#define PERSON_H
class Person{
    private:
        std::string first_name_;
        std::string last_name_;
        std::string school_;
        std::string field_;
        std::unordered_map<std::string, std::string> friends_;
    public:
        Person();
        
        Person(std::string first_name, std::string last_name, std::string school, 
            std::string field, std::unordered_map<std::string, std::string> friends);
        
        std::string getFirstName();
};
#endif