#include "Network2.hpp"


Person* Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    auto look_up_ = network_.find(first_name_ + " " + last_name_);

    //if person not in network then we set to nullptr
    if(look_up_  == network_.end()){
        return nullptr;
    }
    //if they are we return the actual person
    return look_up_->second;
 }


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

/** FRIENDS SECTION **/

bool Network::addFriend(const std::string& friend_first_name, const std::string& friend_last_name_){
    friend_ = lookUp(friend_first_name, friend_last_name_);

    //makes sure the person exist that we will be adding
    if(friend_ != nullptr && current_person_->friendAdd(friend_)){
        return 1;
    }
    return 0;
}

bool Network::removeFriend(const std::string& remove_first, const std::string& remove_last){
    friend_ = lookUp(remove_first, remove_last);

    if(friend_ != nullptr && current_person_->friendRemove(friend_)){
        return 1;    
    }
    return 0;
}

void Network::listFriends(){
    current_person_->friendsList();
    
}

/** PERSON **/

bool Network::addPerson(std::string first_name_, std::string last_name_, 
std::string school_, std::string field_){

        Person* new_person = new Person (first_name_,last_name_,school_,field_, {});
        network_.insert({new_person->getFullName(), new_person});
        return 1;
}

bool Network::removePerson(){
    network_.erase(current_person_->getFullName());
    return 1;
}

bool Network::changePersonName(const std::string& new_first_name, const std::string& new_last_name){
    current_person_->changeFirstName(new_first_name);
    current_person_->changeLastName(new_last_name);
    return 1;
}


bool Network::duplicate(Person* duplicate_friend_){
    auto dup_finder_ = duplicate_table_.find(duplicate_friend_->getFullName());

    if(dup_finder_ != duplicate_table_.end()){
        duplicate_table_[dup_finder_->first] ++;
        return 1;
    }
    return 0;
}