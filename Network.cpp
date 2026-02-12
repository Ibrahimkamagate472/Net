#include "Network.hpp"


/**
 * @brief this function checks in our network if a person is in it or not
 * 
 * @param const reference to a string of the persons first name 
 * @param const reference to a string of the persons last name 
 * 
 * @return true or false if we were able find the person or not
 */

 Person* Network::lookUp(Person& person_){
    auto look_up_ = network_.find(person_.getFullName());

    if(look_up_  == network_.end()){
        return nullptr;
    }
    return &(look_up_->second.person);
 }
// bool Network::lookUp(const std::string& first_name_, const std::string& last_name_){
//     auto look_up_ = network_.find(first_name_ + " " + last_name_);

//     //checks to see if the person is in the network
//     if(look_up_ ==  network_.end()){
//         std::cout << "We are unable to find that person." << std::endl;
//         return 0;
//     }
//     return 1;
// }


/**
 * @brief this function sets the currernt person we are using, if the exist 
 * 
 * @param const reference to a string of the persons first name 
 * @param const reference to a string of the persons last name 
 * 
 */
void Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    Person* temp;
    //checks if there person even exist in our network
    if(!lookUp(*temp)){
        std::cout << "This person does not exist in out network." << std::endl;
        return;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = first_name_ + " " + last_name_;
    delete temp;
}



/**
 * @brief this functions handles if there are duplicate 
 */
bool Network::duplicate(const std::string& indicator_){
    auto person_ = network_.find(current_person_);

    //means that will be a duplicate name 
    if(person_ != network_.end() && indicator_ == "person"){

    }
    else if(person_ != network_.end() && indicator_ == "friend"){

    }
}



void Network::duplicateHandler(const std::string& duplicateName){
    for(auto person_ : network_){
        if(person_.second.person.getFirstName() == duplicateName){

        }
    }
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

/**
 * @brief this function deletes a friend from a persons list 
 * 
 * @param const reference to a string of the person first name we want to remove
 * @param const reference to a string of the person last name we want to remove
 */
void Network::removeFriend(const std::string& remove_first, const std::string& remove_last){
    auto person_ = network_.find(current_person_);
    //finds the friends 
    std::string remove_full_name = remove_first + " " + remove_last;
    auto friend_ = person_->second.friends.find(remove_full_name);
    
    //double check if they are in the friends list
    if(friend_ != person_->second.friends.end()){
        person_->second.friends.erase(remove_first);
        std::cout << "We have removed " << remove_full_name << " from " 
        << current_person_ << " friends list." << std::endl;
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
    network_.insert({first_name_ + " " +last_name_, person_});

    return 1;
}





bool Network::changePersonName(const std::string& new_first_name, const std::string& new_last_name){
    
}