#include <iostream>
#include <string>
#include <vector>
#include <ShlObj.h>
#include <direct.h>

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

class Group
{
private:
    std::vector <int> PersonsInGroup;
    std::string nameOfGroup;

public:
    void setPersonInGroup(int _id)
    {
        PersonsInGroup.push_back(_id);
    }

    void deletePerson(int _id)
    {
        PersonsInGroup.erase(PersonsInGroup.begin() + _id);
    }

    void setNameOfGroup(std::string _nameOfGroup)
    {
        nameOfGroup = _nameOfGroup;
    }

    int getPersonsInGroupSize()
    {
        return PersonsInGroup.size();
    }

    int getPersonIngroup(int i)
    {
        return PersonsInGroup[i];
    }

    std::string getNameOfGroup()
    {
        return nameOfGroup;
    }

    void clearPersonInGroup()
    {
        PersonsInGroup.clear();
    }
};

void AddContact();
void Info();
void List();
void DeleteContact();
void EditContact();
std::string GetPathToDocuments();

std::vector <Person> Persons;
std::vector <Group> Groups;

int lastId = 0;

int main()
{
    setlocale(LC_ALL, "rus");

    Info();

    std::string path = GetPathToDocuments();

    while (true)
    {
        std::string input;
        std::cin >> input;

        if (input == "1")
        {
            List();
            std::cout << std::endl;
            system("pause");
            Info();
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
            DeleteContact();
            std::cout << std::endl;
            system("pause");
            Info();
        }
        else if (input == "4")
        {
            EditContact();
        }
        else if (input == "5")
        {
            //ListOfGroup();
        }
        else if (input == "6")
        {
            AddGroup();
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

void DeleteContact()
{
    List();
    int number;

    std::cout << "\n Contact number to delete: ";
    std::cin >> number;
    number--;

    Persons.erase(Persons.begin() + number);
}

void EditContact()
{
    int id;
    std::string name, lastname, number;
    List();

    std::cout << "\n Choose contact number: ";
    std::cin >> id;
    system("cls");
    id--;

    name = Persons[id].getName();
    lastname = Persons[id].getLastName();
    number = Persons[id].getNumber();

    std::cout << "\n You chose " << name << " " << lastname << ": " << number << std::endl;
    std::cout << "\n\n What you want to edit?" << "\n\n 1. Name\n 2. Lastname\n 3. Number\n\n Input number: ";
    std::cin >> number;

    if (number == "1")
    {
        system("cls");

        std::cout << "\n Previous name: " << name << "\n\n Input new name: ";
        std::cin >> lastname;
        Persons[id].setName(lastname);

        std::cout << "\n Successfully, previous name - " << name << ", new name - " << lastname << "\n" << std::endl;

        system("pause");
        Info();
    }

    else if (number == "2")
    {
        system("cls");

        std::cout << "\n Previous lastname: " << lastname << "\n\n Input new lastname: ";
        std::cin >> name;
        Persons[id].setLastName(name);

        std::cout << "\n Successfully, previous lastname - " << lastname << ", new lastname - " << name << "\n" << std::endl;

        system("pause");
        Info();
    }

    else if (number == "3")
    {
        system("cls");

        number = Persons[id].getNumber();

        std::cout << "\n Previous number: " << number << "\n\n Input new number: ";
        std::cin >> name;
        Persons[id].setNumber(name);

        std::cout << "\n Successfully, previous number - " << number << ", new number - " << name << "\n" << std::endl;

        system("pause");
        Info();
    }
}

std::string GetPathToDocuments()
{
    wchar_t* pBuffer = new wchar_t[1000];
    SHGetFolderPathW(NULL, CSIDL_MYDOCUMENTS, NULL, SHGFP_TYPE_CURRENT, pBuffer);
    std::wstring wpath = pBuffer;
    std::string path(wpath.begin(), wpath.end());
    return path;
}

void AddGroup()
{
    system("cls");
    Group newGroup;
    std::string buffer;

    std::cout << "\n Input name of group: ";
    std::cin >> buffer;

    newGroup.setNameOfGroup(buffer);

    std::cout << "\n Add person in group now(1) or later(2): ";
    std::cin >> buffer;

    if (buffer == "1")
    {
        std::cout << "\n\n List if persons:\n\n";

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

        while (true)
        {
            std::cout << "\nInput person number (0-exit): ";
            std::cin >> buffer;

            if (buffer != "0")
            {
                newGroup.setPersonInGroup(std::stoi(buffer) - 1);
                std::cout << "Added" << std::endl;
            }
            else
            {
                break;
            }
        }

        Groups.push_back(newGroup);
    }
}