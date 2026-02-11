#include "Person.hpp"

Person::Person(){}

Person::Person(std::string first_name, std::string last_name, std::string school, 
    std::string field, std::unordered_map<std::string, std::string> friends):
first_name_{first_name}, last_name_{last_name}, school_{school}, field_{field}, friends_{friends}{}

std::string Person::getFirstName(){
    return first_name_;
}
