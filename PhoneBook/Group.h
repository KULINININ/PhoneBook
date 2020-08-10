#pragma once
#include <iostream>
#include <vector>

namespace PhoneBook
{
    class Group
    {
    private:
        std::vector <int> PersonsInGroup;
        std::string nameOfGroup;

    public:
        void setPersonInGroup(int _id);
        void deletePerson(int _id);
        void setNameOfGroup(std::string _nameOfGroup);
        int getPersonsInGroupSize();
        int getPersonIngroup(int i);
        std::string getNameOfGroup();
        void clearPersonInGroup();
    };
}