#pragma once
#include <iostream>

namespace PhoneBook
{
    class Person
    {
    private:
        int id = 0;
        std::string number;
        std::string name;
        std::string lastname;

    public:
        void setName(std::string _name);
        void setLastName(std::string _lastname);
        void setNumber(std::string _number);
        void setId(int _id);
        std::string getName();
        std::string getLastName();
        std::string getNumber();
        int getId();
    };
}