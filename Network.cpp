#include "Network.hpp"

/**
 * @brief functions adds a new people to out network
 * 
 */
bool Network::addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_){
Person person_ (first_name_, last_name_, school_, field_, 0);

newtork_[id_] = person_;

}