#include <iostream>
#include <string>

class Person
{
private:
    int id = 0;
    std::string number;
    std::string name;
    std::string lastname;

public:
    void setName(std::string _name)
    {
        name = _name;
    }

    void setLastName(std::string _lastname)
    {
        lastname = _lastname;
    }

    void setNumber(std::string _number)
    {
        number = _number;
    }

    void setId(int _id)
    {
        id = _id;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    while (true)
    {
        std::string input;
        std::cin >> input;

        if (input == "1")
        {
            //List();
        }
        else if (input == "2")
        {
            //AddContact();
        }
        else if (input == "3")
        {
            //DeleteContact();
        }
        else if (input == "4")
        {
            //EditContact();
        }
        else if (input == "5")
        {
            //ListOfGroup();
        }
        else if (input == "6")
        {
            //AddGroup();
        }
        else if (input == "7")
        {
            //DeleteGroup();
        }
        else if (input == "8")
        {
            //EditGroup();
        }
        else if (input == "9")
        {
            //Save
        }
        else if (input == "10")
        {
            //Save and exit
        }
    }
}