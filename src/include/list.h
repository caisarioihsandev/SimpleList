#include <iostream>
#include <vector>
// using namespace std;

class List {
    private:

    protected:

    public:
        List() {
            // constructor
        }
        ~List() {
            // destructor
        }
        std::vector<std::vector<std::string>> mainList;
        std::vector<std::string> list;
        std::string name;
        int currentUserIndex;

        void printMenu();
        void printList();
        void addItem();
        void deleteItem();
        bool findUserList();
        void saveList();
};