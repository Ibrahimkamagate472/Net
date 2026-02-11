#include "Network.hpp"

/**
 * @brief this function checks in our network if a person is in it or not
 * 
 * @param const reference to a string of the persons first name 
 * @param const reference to a string of the persons last name 
 * 
 * @return true or false if we were able find the person or not
 */
bool Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    setCurrentPerson(first_name_,last_name_);
    auto look_up_ = network_.find(current_person_);

    //checks to see if the person is in the network
    if(look_up_ ==  network_.end()){
        std::cout << "We are unable to find that person." << std::endl;
        return 0;
    }
    return 1;
}

/**
 * @brief this function sets the currernt person we are using, if the exist 
 * 
 * @param const reference to a string of the persons first name 
 * @param const reference to a string of the persons last name 
 * 
 */
void Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    
    //checks if there person even exist in our network
    if(!lookUp(first_name_, last_name_)){
        std::cout << "This person does not exist in out network." << std::endl;
        return;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = first_name_ + " " + last_name_;
}
/* FRIENDS SECTION */

/**
 * @brief this functions adds a friend to the current preson that we are using 
 * 
 * @param const reference to a string of the friend we are adding first name
 * @param const reference to a string of the friend we are adding last name
 * 
 * @return true or false if we were able to add the friend
 */
bool Network::addFriend(const std::string& friend_first_name, const std::string& friend_last_name_){
    auto it = network_.find(current_person_);

    //makes sure the person exist that we will be adding
    if(lookUp(friend_first_name, friend_last_name_)){
        //added the friend to the current person friends list
        it->second.friends.insert(friend_first_name + " "+ friend_last_name_, 
            friend_first_name + " "+ friend_last_name_);
        return 1;
    }
    return 0;
}

/**
 * @brief this function list out all the friends for a current person
 */
void Network::listFriends(){
    auto person_ = network_.find(current_person_);

    if(person_ != network_.end()){
        for(const auto friend_ : person_->second.friends){
            std::cout << friend_.first;
        }
    }
}


/* BASIC FUNCTIONS */

/**
 * @brief functions adds a new people to out network
 * 
 */
bool Network::addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_){
    
    Person temp_person_ (first_name_, last_name_, school_, field_, {});

    Entry person_;
    person_.friends = {};
    person_.person = temp_person_;

    network_[first_name_] = person_;

    

    return 1;
}