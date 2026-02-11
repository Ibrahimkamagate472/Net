#include <iostream>
#include <unordered_map>
#include "Person.hpp"


#ifndef NETWORK_H
#define NETWORK_H

struct Entry{
    Person person;
    std::unordered_map<std::string, std::string> friends;
};

class Network{

    private:
        int id_;
        std::unordered_map<std::string ,Entry> network_;
        std::string current_person_;

    public:
    /**
     * @brief this function checks in our network if a person is in it or not
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     * @return true or false if we were able find the person or not
     */
    bool lookUp(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief this function sets the currernt person we are using, if the exist 
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     */
    void setCurrentPerson(const std::string& first_name_, const std::string& last_name_);

    /* FRIENDS SECTION */
    
    /**
     * @brief this functions adds a friend to the current preson that we are using 
     * 
     * @param const reference to a string of the friend we are adding first name
     * @param const reference to a string of the friend we are adding last name
     * 
     * @return true or false if we were able to add the friend
     */
    bool addFriend(const std::string& friend_first_name, const std::string& friend_last_name_);


    /**
     * @brief this function list out all the friends for a current person
     */
    void listFriends();





    
    /**
     * @brief functions adds a new people to out network
     * 
     */
    bool addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_);


    /**
     * 
     */
    bool recomendFriend();

    /**
     * 
     */
    bool removeFriend();


};
#endif