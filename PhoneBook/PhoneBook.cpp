#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ShlObj.h>
#include <direct.h>
#include "Person.h"
#include "Group.h"
#pragma warning(disable : 4996)

void Info();
void AddContact();
void List();
void Save(std::string path);
void Load(std::string pat);
void DeleteContact();
void EditContact();
void AddGroup();
void ListOfGroup();
void LoadGroup(std::string path);
void SaveGroup(std::string path);
void DeleteGroup();
void EditGroup();
std::string GetPathToDocuments();
void CreateFolder(std::string path);

std::vector <PhoneBook::Person> Persons;
std::vector <PhoneBook::Group> Groups;

int lastId = 0;

int main()
{
    setlocale(LC_ALL, "rus");

    Info();

    std::string path = GetPathToDocuments();

    CreateFolder(path);
    Load(path);
    LoadGroup(path);

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
            ListOfGroup();
            Info();
        }
        else if (input == "6")
        {
            AddGroup();
            Info();
        }
        else if (input == "7")
        {
            DeleteGroup();
            Info();
        }
        else if (input == "8")
        {
            EditGroup();
        }
        else if (input == "9")
        {
            Save(path);
            SaveGroup(path);
            std::cout << "Saved" << std::endl;
            system("pause");
            system("cls");
            Info();
        }
        else if (input == "10")
        {
            Save(path);
            SaveGroup(path);

            break;
        }
    }
}

void Info()
{
    system("cls");

    std::cout << "\n 1. List of contact\n\n 2. Add contact \n\n 3. Delete contact\n\n 4. Edit contact\n\n 5. List of group\n\n 6. Add group\n\n 7. Delete group\n\n 8. Edit group\n\n 9. Save\n\n 10. Exit and save\n\n\n Input: ";
}

void AddContact()
{
    system("cls");

    PhoneBook::Person newPerson;

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

    Persons.push_back(newPerson);
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

void Save(std::string path)
{
    path += "\\PhoneBook\\data.txt";
    std::ofstream saveData(path);
    for (size_t i = 0; i < Persons.size(); i++)
    {
        saveData << "name: " << Persons[i].getName() << std::endl;
        saveData << "lastname: " << Persons[i].getLastName() << std::endl;
        saveData << "number: " << Persons[i].getNumber() << std::endl;
        saveData << "id: " << Persons[i].getId() << std::endl;
        saveData << "---" << std::endl;
    }

    saveData << "end" << std::endl;
    saveData.close();
}

void SaveGroup(std::string path)
{
    path += "\\PhoneBook\\groups.txt";

    std::ofstream saveGroups(path);

    saveGroups << "lastId: " << lastId << std::endl;
    saveGroups << "---" << std::endl;

    for (size_t i = 0; i < Groups.size(); i++)
    {
        int size = Groups[i].getPersonsInGroupSize();
        std::string nameOfGroup = Groups[i].getNameOfGroup();
        saveGroups << "NameOfGroup: " << nameOfGroup << std::endl;

        for (size_t j = 0; j < size; j++)
        {
            saveGroups << "id: " << Groups[i].getPersonIngroup(j) << std::endl;
        }
        saveGroups << "---" << std::endl;
    }

    saveGroups << "end" << std::endl;
    saveGroups.close();
}

void Load(std::string path)
{
    path += "\\PhoneBook\\data.txt";
    std::ifstream loader(path);
    if (loader.good())
    {
        PhoneBook::Person newPerson;
        std::string buffer;

        while (true)
        {
            loader >> buffer;

            if (buffer == "name:")
            {
                loader >> buffer;
                newPerson.setName(buffer);
            }
            else if (buffer == "lastname:")
            {
                loader >> buffer;
                newPerson.setLastName(buffer);
            }
            else if (buffer == "number:")
            {
                loader >> buffer;
                newPerson.setNumber(buffer);
            }
            else if (buffer == "id:")
            {
                loader >> buffer;
                newPerson.setId(std::stoi(buffer));
            }
            else if (buffer == "---")
            {
                Persons.push_back(newPerson);
            }
            else if (buffer == "end")
            {
                break;
            }
        }

        loader.close();
    }
}

void LoadGroup(std::string path)
{
    path += "\\PhoneBook\\groups.txt";

    PhoneBook::Group newGroup;

    std::string buffer;
    std::ifstream loader(path);

    if (loader.good())
    {
        while (true)
        {
            loader >> buffer;

            if (buffer == "lastId:")
            {
                loader >> buffer;
                lastId = std::stoi(buffer);
                loader >> buffer;
            }
            else if (buffer == "NameOfGroup:")
            {
                loader >> buffer;
                newGroup.setNameOfGroup(buffer);
            }
            else if (buffer == "id:")
            {
                loader >> buffer;
                newGroup.setPersonInGroup(std::stoi(buffer));
            }
            else if (buffer == "---")
            {
                Groups.push_back(newGroup);
                newGroup.clearPersonInGroup();
            }
            else if (buffer == "end")
            {
                break;
            }
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
//Удалять из группы
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

void AddGroup()
{
    system("cls");
    PhoneBook::Group newGroup;
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

void ListOfGroup()
{
    system("cls");
    std::cout << std::endl;
    int input, id, _id;
    std::string buffer;

    for (size_t i = 0; i < Groups.size(); i++)
    {
        std::cout << " " << i + 1 << ". " << Groups[i].getNameOfGroup() << std::endl;
    }

    std::cout << "\n View in full information about group number (0-exit): ";
    std::cin >> input;
    std::cout << std::endl;

    if (input != 0)
    {
        input--;
        int PersonsInGroupSize = Groups[input].getPersonsInGroupSize();

        for (size_t i = 0; i < PersonsInGroupSize; i++)
        {
            id = Groups[input].getPersonIngroup(i);

            for (size_t j = 0; j < Persons.size(); j++)
            {
                _id = Persons[j].getId();

                if (id == _id)
                {
                    std::cout << " " << i + 1 << ". ";
                    buffer = Persons[j].getName();
                    std::cout << buffer;
                    buffer = Persons[j].getLastName();
                    std::cout << " " << buffer;
                    buffer = Persons[j].getNumber();
                    std::cout << ": " << buffer << std::endl;
                    std::cout << std::endl;
                }
            }
        }
    }

    std::cout << std::endl;

    system("pause");
}

void DeleteGroup()
{
    system("cls");
    std::cout << std::endl;
    std::string buffer;

    for (size_t i = 0; i < Groups.size(); i++)
    {
        std::cout << " " << i + 1 << ". " << Groups[i].getNameOfGroup() << std::endl;
    }

    std::cout << "\n Which group to delete: ";
    std::cin >> buffer;

    Groups.erase(Groups.begin() + std::stoi(buffer) - 1);

    std::cout << std::endl;
    system("pause");
}

void EditGroup()
{
    system("cls");

    std::cout << std::endl;
    std::string buffer;
    int groupId, id, _id;

    for (size_t i = 0; i < Groups.size(); i++)
    {
        std::cout << " " << i + 1 << ". " << Groups[i].getNameOfGroup() << std::endl;
    }

    std::cout << "\n Which group to change: ";
    std::cin >> buffer;
    groupId = std::stoi(buffer);
    groupId--;

    std::cout << "\n Group you selected: " << Groups[groupId].getNameOfGroup();

    std::cout << "\n\n Edit name of group (1) or edit persons in group(2) ?: ";
    std::cin >> buffer;

    if (buffer == "1")
    {
        std::cout << "\n Input new name: ";
        std::cin >> buffer;

        Groups[groupId].setNameOfGroup(buffer);
    }

    else if (buffer == "2")
    {
        std::cout << "\n List of person in this group:\n" << std::endl;

        int PersonsInGroupSize = Groups[groupId].getPersonsInGroupSize();

        for (size_t i = 0; i < PersonsInGroupSize; i++)
        {
            id = Groups[groupId].getPersonIngroup(i);

            for (size_t j = 0; j < Persons.size(); j++)
            {
                _id = Persons[j].getId();

                if (id == _id)
                {
                    std::cout << " " << i + 1 << ". ";
                    buffer = Persons[j].getName();
                    std::cout << buffer << " ";
                    buffer = Persons[j].getLastName();
                    std::cout << buffer << ": ";
                    buffer = Persons[j].getNumber();
                    std::cout << buffer << std::endl;
                }
            }
        }

        std::cout << "\n Add(1) or delete(2) persons?: ";
        std::cin >> buffer;

        if (buffer == "1")
        {
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
                    Groups[groupId].setPersonInGroup(std::stoi(buffer) - 1);
                    std::cout << "Added" << std::endl;
                }
                else
                {
                    break;
                }
            }
        }
        else if (buffer == "2")
        {
            std::cout << std::endl;

            int PersonsInGroupSize = Groups[groupId].getPersonsInGroupSize();

            for (size_t i = 0; i < PersonsInGroupSize; i++)
            {
                id = Groups[groupId].getPersonIngroup(i);

                for (size_t j = 0; j < Persons.size(); j++)
                {
                    _id = Persons[j].getId();

                    if (id == _id)
                    {
                        std::cout << " " << i + 1 << ". ";
                        buffer = Persons[j].getName();
                        std::cout << buffer << " ";
                        buffer = Persons[j].getLastName();
                        std::cout << buffer << ": ";
                        buffer = Persons[j].getNumber();
                        std::cout << buffer << std::endl;
                    }
                }
            }

            while (true)
            {
                std::cout << "\nInput person number (0-exit): ";
                std::cin >> buffer;

                if (buffer != "0")
                {
                    Groups[groupId].deletePerson(std::stoi(buffer) - 1);
                    std::cout << "Deleted" << std::endl;
                }
                else
                {
                    break;
                }
            }
        }
    }

    std::cout << std::endl;
    system("pause");
    Info();
}

std::string GetPathToDocuments()
{
    wchar_t* pBuffer = new wchar_t[1000];
    SHGetFolderPathW(NULL, CSIDL_MYDOCUMENTS, NULL, SHGFP_TYPE_CURRENT, pBuffer);
    std::wstring wpath = pBuffer;
    std::string path(wpath.begin(), wpath.end());
    return path;
}

void CreateFolder(std::string path)
{
    path += "\\PhoneBook";
    char str[100];
    strcpy(str, path.c_str());
    mkdir(str);
}