#include "Group.h"
#include <iostream>

void PhoneBook::Group::setPersonInGroup(int _id)
{
    PersonsInGroup.push_back(_id);
}

void PhoneBook::Group::deletePerson(int _id)
{
    PersonsInGroup.erase(PersonsInGroup.begin() + _id);
}

void PhoneBook::Group::setNameOfGroup(std::string _nameOfGroup)
{
    nameOfGroup = _nameOfGroup;
}

int PhoneBook::Group::getPersonsInGroupSize()
{
    return PersonsInGroup.size();
}

int PhoneBook::Group::getPersonIngroup(int i)
{
    return PersonsInGroup[i];
}

std::string PhoneBook::Group::getNameOfGroup()
{
    return nameOfGroup;
}

void PhoneBook::Group::clearPersonInGroup()
{
    PersonsInGroup.clear();
}