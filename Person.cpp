#include "Person.hpp"

Person::Person(){}

Person::Person(std::string first_name, std::string last_name, std::string school, 
std::string field, std::unordered_map<std::string, std::string> friends):
first_name_{first_name}, last_name_{last_name}, school_{school}, field_{field}, friends_{friends}{}

/** GETTERS **/
/**
 * @brief this function gets the first name of a person
 * 
 * @return returns a string to the person's first name 
 */
std::string Person::getFirstName(){
    return first_name_;
}

/**
 * @brief this function gets the last name of a person
 * 
 * @return returns a string to the person's last name 
 */
std::string Person::getLastName(){
    return last_name_;
}

/**
 * @brief this function returns a persons full name
 * 
 * @return the full name of the person
 */
std::string Person::getFullName(){
    return first_name_ + " " + last_name_;
}


/** SETTERS **/

/**
 * @brief this function gets the first name of a person
 * 
 * @param const reference to a string of the first name
 */
void Person::setFirstName(const std::string& first_){
    first_name_ = first_;
}

/**
 * @brief this function gets the last name of a person
 * 
 * @param const reference to a string of the last name 
 */
void Person::setLastName(const std::string& last_){
    last_name_ = last_;
}

/**
 * @brief this function gets the last name of a person
 * 
 * @param const reference to a string of the school
 */
void Person::setSchool(const std::string& college_){
    school_ = college_;
}


/**
 * @brief this function gets the last name of a person
 * 
 * @param const reference to a string of the field
 */
void Person::setField(const std::string& job_){
    field_ = job_;
}


/** MUTATORS **/

/**
 * @brief this function changes the first name of a person
 * 
 * @param const reference to a string of the new first name 
 * 
 * @return true or false if done
 */
bool Person::changeFirstName(const std::string& first_){
    first_name_ = first_;
}

/**
 * @brief this function changes the first name of a person
 * 
 * @param const referent to a string of the new last name
 * 
 * @return true or false if done
 */
bool Person::changeLastName(const std::string& last_){
    last_name_ = last_;
}
