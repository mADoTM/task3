#include "DoubleLinkedList.h"

int main() {
    // iterator прямой обратный
    // copy constructor

    DoubleLinkedList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    std::cout << "Int list: " << std::endl;
    for (auto it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    DoubleLinkedList<std::string> strList;
    strList.push_back("Petr");
    strList.push_back("Sergeevich");
    strList.push_back("!");

    std::cout << "String list: " << std::endl;
    for (auto it = strList.begin(); it != strList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Int copy reversed list: " << std::endl;

    DoubleLinkedList<int> newList(intList);
    for (auto it = newList.rbegin(); it != newList.rend(); it--) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    DoubleLinkedList<int> newListAgain(intList);
    std::cout << "for with iterator\n";
    auto iterator = newList.rbegin();
    for(int i = 0; i < 100; i++) {
        if(iterator != nullptr) {
            std::cout << *iterator << " ";
        } else {
            std::cout << "null ";
        }
        iterator--;
    }
    std::cout << std::endl;
    std::cout << "for with iterator prefix increment\n";
    for (auto it = newList.rbegin(); it != newList.rend(); --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}