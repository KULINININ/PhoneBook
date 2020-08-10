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

    std::string getName()
    {
        return name;
    }

    std::string getLastName()
    {
        return lastname;
    }

    std::string getNumber()
    {
        return number;
    }

    int getId()
    {
        return id;
    }
};

void AddContact();
void Info();
void List();

std::vector <Person> Persons;

int lastId = 0;

int main()
{
    setlocale(LC_ALL, "rus");

    Info();

    while (true)
    {
        std::string input;
        std::cin >> input;

        if (input == "1")
        {
            List();
        }
        else if (input == "2")
        {
            AddContact();
            std::cout << std::endl;
            system("pause");
            Info();
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

void Info()
{
    system("cls");

    std::cout << "\n 1. List of contact\n\n 2. Add contact \n\n 3. Delete contact\n\n 4. Edit contact\n\n 5. List of group\n\n 6. Add group\n\n 7. Delete group\n\n 8. Edit group\n\n 9. Save\n\n 10. Exit and save\n\n\n Input: ";
}

void List()
{
    system("cls");

    std::string buffer;

    if (Persons.size() == 0)
    {
        std::cout << "\n Empty\n";
    }
    else
    {
        std::cout << "\n";

        for (size_t i = 0; i < Persons.size(); i++)
        {
            std::cout << " " << i + 1 << ". ";
            buffer = Persons[i].getName();
            std::cout << buffer;
            buffer = Persons[i].getLastName();
            std::cout << " " << buffer;
            buffer = Persons[i].getNumber();
            std::cout << ": " << buffer << std::endl;
            std::cout << std::endl;
        }
    }
}
