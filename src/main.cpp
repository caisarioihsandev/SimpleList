#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[]) {
    List simpleList;
    Database data;

    if(arg_count > 1) {
        simpleList.name = std::string(args[1]);
        simpleList.mainList = data.read();
        bool userFound = simpleList.findUserList();
        simpleList.printMenu();
        data.write(simpleList.mainList);
    }
    else {
        std::cout << "Username not supplied.. exiting the program" << std::endl;
    }    

    return 0;
}