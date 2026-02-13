#include <iostream>
#include <unordered_map>
#include "Person.hpp"


#ifndef NETWORK2_H
#define NETWORK2_H

class Network{

    private:
        int id_;
        std::unordered_map<std::string ,Person*> network_;
        std::unordered_map<std::string, std::string> duplicate_;
        Person* current_person_;
        Person* person_;
        Person* friend_;

    public:
    /**
     * @brief this function checks in our network if a person is in it or not
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     * @return true or false if we were able find the person or not
     */
    Person* lookUp(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief this function sets the currernt person we are using, if the exist 
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     */
    bool setCurrentPerson(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief this functions handles if there are duplicate 
     */
    bool duplicate(const std::string& indicator_);

    void duplicateHandler(const std::string& duplicateName);

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
     * @brief this function deletes a friend from a persons list 
     * 
     * @param const reference to a string of the person first name we want to remove
     * @param const reference to a string of the person last name we want to remove
     */
    bool removeFriend(const std::string& remove_first, const std::string& remove_last);

    /**
     * 
     */
    bool recomendFriend();




    
    /**
     * @brief functions adds a new people to out network
     * 
     */
    bool addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_);
    bool removePerson();
    bool changePersonName(const std::string& new_first_name, const std::string& new_last_name);


};
#endif