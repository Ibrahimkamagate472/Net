#include "Network2.hpp"


Person* Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    auto look_up_ = network_.find(first_name_ + " " + last_name_);

    if(look_up_  == network_.end()){
        return nullptr;
    }
    return &(look_up_->second.person);
 }


 void Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    //creates a temp person
    auto person = lookUp(first_name_, last_name_);

    //checks if there person even exist in our network
    if(person == nullptr){
        std::cout << "This person does not exist in out network." << std::endl;
        return;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = person;
}


bool Network::addFriend(const std::string& friend_first_name, const std::string& friend_last_name_){
    auto it = lookUp(*current_person_);

    Person* temp_friend;
    temp_friend->setFirstName(friend_first_name);
    temp_friend->setLastName(friend_last_name_);

    //makes sure the person exist that we will be adding
    if(lookUp(*temp_friend) != nullptr && it != nullptr){
        //added the friend to the current person friends list
        it.
        return 1;
    }
    return 0;
}