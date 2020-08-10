#include <iostream>
#include <string>
#include <vector>

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

void AddContact();

std::vector <Person> Persons;

int lastId = 0;

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
            AddContact();
            std::cout << std::endl;
            system("pause");
            //Info();
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

void AddContact()
{
    system("cls");

    Person newPerson;

    std::string buffer;

    lastId++;
    int id = lastId;

    std::cout << "\nname: ";
    std::cin >> buffer;
    newPerson.setName(buffer);

    std::cout << "\nlastname: ";
    std::cin >> buffer;
    newPerson.setLastName(buffer);

    std::cout << "\nnumber: ";
    std::cin >> buffer;
    newPerson.setNumber(buffer);

    newPerson.setId(id);
}
