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
        std::vector<std::string> list;
        std::string name;

        void printMenu();
        void printList();
        void addItem();
        void deleteItem();
};