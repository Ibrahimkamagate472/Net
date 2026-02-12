#include "Network2.hpp"


Person* Network::lookUp(Person& person_){
    auto look_up_ = network_.find(person_.getFullName());

    if(look_up_  == network_.end()){
        return nullptr;
    }
    return &(look_up_->second.person);
 }


 void Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    //creates a temp person
    Person* temp;
    temp->setFirstName(first_name_);
    temp->setLastName(last_name_);

    //checks if there person even exist in our network
    if(lookUp(*temp) == nullptr){
        std::cout << "This person does not exist in out network." << std::endl;
        return;
    }
    //if they do they we set it to the current person that we want to minipluate
    Person* current_person_ = lookUp(*temp);
    delete temp;
}