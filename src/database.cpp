#include "include/database.h"

void Database::write(std::vector<std::vector<std::string>> mainList) {
    
    std::ofstream db;
    db.open("db/lists.sl");

    if (db.is_open())
    {
        for (size_t userIndex = 0; userIndex < mainList.size(); userIndex++)
        {
            for (size_t listIndex = 0; listIndex < mainList[userIndex].size(); listIndex++)
            {
                if (listIndex == 0)
                {
                    db << "#" << mainList[userIndex][listIndex] << std::endl;
                }
                else
                {
                    db << mainList[userIndex][listIndex] << std::endl;    
                }
            }
            db << "%" << std::endl;
        }
    }
    else 
    {
        std::cout << "Cannot open file for writing." << std::endl;
    }
    
    db.close();

}

std::vector<std::vector<std::string>> Database::read() {
    std::string line;
    std::ifstream db;

    std::vector<std::string> userList;
    db.open("db/lists.sl");

    if (db.is_open())
    {
        while (std::getline(db, line, '\n'))
        {
            if (line.front() == '#')
            {
                std::cout << "Found a Hashtag: " << line << std::endl;
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if (line.front() == '%')
            {
                std::cout << "Found a Percentage: " << line << std::endl;
                mainList.push_back(userList);
                userList.clear();
            }
            else
            {
                std::cout << "Found a Item: " << line << std::endl;
                userList.push_back(line);
            }
            
            
                        
        }
        
    }
    else
    {
        std::cout << "Cannot open file for reading." << std::endl;
    }
    
    db.close();

    return mainList;
    
}