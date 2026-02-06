#include <iostream>
#include <unordered_map>
#include "Person.hpp"


#ifndef NETWORK_H
#define NETWORK_H

struct Entry{
    Person Person;
    std::vector<std::string> friends;
};

class Network{

    private:
        int id_;
        std::unordered_map<int ,Person> newtork_;
        std::unordered_map<int ,Entry> people_;
        std::vector<Entry> pending;
    public:
    /**
     * @brief functions adds a new people to out network
     * 
     */
    bool addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_){};

    /**
     * 
     */
    bool addFriend(){};

    /**
     * 
     */
    bool recomendFriend(){};

    /**
     * 
     */
    bool removeFriend(){};


};
#endif