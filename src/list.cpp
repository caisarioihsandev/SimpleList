#include "include/list.h"

void List::printMenu() {
    int choice;

    std::cout << "*********************" << std::endl;
    std::cout << "1 - Print list.\n";
    std::cout << "2 - Add to list.\n";
    std::cout << "3 - Delete from list.\n";
    std::cout << "4 - Save list.\n";
    std::cout << "5 - Quit.\n";
    std::cout << "Enter your choice and press return: ";

    std::cin >> choice;

    if (choice == 5)
    {
        return;
    }
    else if (choice == 4)
    {
        saveList();
    }
    
    else if (choice == 3)
    {
        deleteItem();
    }
    else if (choice == 2)
    {
        addItem();
    }
    else if (choice == 1)
    {
        printList();
    }        
    else
    {
        std::cout << "Sorry,, choice is not implemented yet..!!" << std::endl;
    }
}

void List::addItem() {
    std::cout << "\n\n\n\n\n\n\n\n" ;
    std::cout << "*** Add Item ***" << std::endl;
    std::cout << "Type in an item and press enter: ";

    std::string item;
    std::cin >> item;

    list.push_back(item);

    std::cout << "Successfully added an item to the list. \n\n\n\n";
    std::cin.clear();

    printMenu();
}

void List::deleteItem() {
    std::cout << "*** Delete Item ***" << std::endl;
    
    if (list.size())
    {
        for (size_t i = 0; i < list.size(); i++)
        {
            std::cout << i << ": " << list[i] << std::endl;
        }

        std::cout << "\nSelect an item index number to delete: ";

        int choiceNum;
        std::cin >>choiceNum;

        list.erase(list.begin()+choiceNum);        
    }
    else 
    {
        std::cout << "No items to delete" << std::endl;
    }

    printMenu();
}

void List::printList() {
    std::cout << "\n\n\n\n\n\n";
    std::cout << "*** Printing List ***" << std::endl;

    for (size_t listIndex = 0; listIndex < list.size(); listIndex++)
    {
        std::cout << " * " << list[listIndex] << std::endl;
    }

    std::cout << "M - Menu" << std::endl;
    char choice;
    std::cin >> choice;

    if (choice == 'M' || choice == 'm')
    {
        printMenu();
    }
    else 
    {
        std::cout << "Invalid Coice. Quitting...!" << std::endl;
    }
    
}

bool List::findUserList() {
    bool userFound = false;
    std::cout << "\n\n\n\n\n\n";
    std::cout << "*** Welcome " << name << " ***" << std::endl;

    for (size_t userIndex = 0; userIndex < mainList.size(); userIndex++)
    {
        std::cout << mainList[userIndex][0] << std::endl;
        if (mainList[userIndex][0] == name)
        {
            std::cout << "User has been found: " << mainList[userIndex][0] << std::endl;
            list = mainList[userIndex];
            currentUserIndex = userIndex;
            userFound = true;
            break;
        }
    }

    if (userFound == false)
    {
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size()-1;
    }

    return userFound;    
}

void List::saveList() {
    std::cout << "Saving the list..." << std::endl;
    mainList[currentUserIndex] = list;
    printMenu();
}