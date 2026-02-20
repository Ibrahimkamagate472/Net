#include "Network.hpp"

/** BASIC FUNCTIONS **/

/**
 * @brief this functions looks through our network for a perso
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last name 
 * 
 * @return a pointer to the person
 */
Person* Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    auto look_up_ = network_.find(first_name_ + " " + last_name_);

    //if person not in network then we set to nullptr
    if(look_up_  == network_.end()){
        return nullptr;
    }
    //if they are we return the actual person
    return look_up_->second;
 }

/**
 * @brief this function sets the currerent person
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last nmae
 * 
 * @return true or flase if done
 */
 bool Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    person_ = lookUp(first_name_, last_name_);

    //checks if there person even exist in our network
    if(person_ == nullptr){
        std::cout << "This person does not exist in our network." << std::endl;
        return 0;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = person_;
    return 1;
}


/** PERSON **/

/**
 * @brief this function adds a person to the network
 * 
 * @param const reference to a string of the first name
 * @param const reference to a string of the last name
 * @param const reference to a string of the school
 * @param const reference to a string of the field
 * 
 * @return true or false 
 */
bool Network::addPerson(std::string first_name_, std::string last_name_, 
    std::string school_, std::string field_){
    
            Person* new_person = new Person (first_name_,last_name_,school_,field_, {});
            network_.insert({new_person->getFullName(), new_person});
            return 1;
    }

/**
 * @brief this function removes a person from the network 
 * 
 * @return true or false 
 */
bool Network::removePerson(){
    network_.erase(current_person_->getFullName());
    return 1;
}

bool Network::changePersonName(const std::string& new_first_name, const std::string& new_last_name){
    current_person_->changeFirstName(new_first_name);
    current_person_->changeLastName(new_last_name);
    return 1;
}

/** FRIENDS SECTION **/

/**
 * @brief this function add a friend to the current person that we are on
 * 
 * @param const reference to a string of the friends first name 
 * @param const reference to a string of the friends last name
 * 
 * @return true or false if done 
 */
bool Network::addFriend(const std::string& friend_first_name, const std::string& friend_last_name_){
    friend_ = lookUp(friend_first_name, friend_last_name_);

    //makes sure the person exist that we will be adding
    if(friend_ != nullptr && current_person_->friendAdd(friend_)){
        return 1;
    }
    return 0;
}

/**
 * @brief this function removes a friend from the current person that we are on 
 * 
 * @param const reference to a string of the friends first name that we want to remove
 * @param const reference to a string of the friends last name that we want to remove
 * 
 * @return true or false if done
 */
bool Network::removeFriend(const std::string& remove_first, const std::string& remove_last){
    friend_ = lookUp(remove_first, remove_last);

    if(friend_ != nullptr && current_person_->friendRemove(friend_)){
        return 1;    
    }
    return 0;
}
/**
 * @brief this function list all the friends of the current person
 */
void Network::listFriends(){
    current_person_->friendsList();
    
}

/** DUPLICATE HANDLER SECTION **/
/**
 * @brief this function adds a duplicate person to the network
 * 
 * 
 */
void Network::addDuplicate(Person* duplicate_person_){
    //find the person in the dup table
    auto person_ = duplicate_table_.find(duplicate_person_->getFullName());

    //this is the first duplicate for that name
    if(person_ == duplicate_table_.end()){
        duplicate_table_[duplicate_person_->getFullName()] = 2;
    }
    //if there is more than one person for that name then we increase the total by 1
    duplicate_table_[duplicate_person_->getFullName()] ++;
}