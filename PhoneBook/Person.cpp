#include "Person.h"
#include <iostream>

void PhoneBook::Person::setName(std::string _name)
{
    name = _name;
}

void PhoneBook::Person::setLastName(std::string _lastname)
{
    lastname = _lastname;
}

void PhoneBook::Person::setNumber(std::string _number)
{
    number = _number;
}

void PhoneBook::Person::setId(int _id)
{
    id = _id;
}

std::string PhoneBook::Person::getName()
{
    return name;
}

std::string PhoneBook::Person::getLastName()
{
    return lastname;
}

std::string PhoneBook::Person::getNumber()
{
    return number;
}

int PhoneBook::Person::getId()
{
    return id;
}