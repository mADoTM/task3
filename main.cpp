#include "DoubleLinkedList.h"

int main() {
    DoublyLinkedList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.pop_back();
    intList.print();
    std::cout << "reversed" << std::endl;
    intList.reversePrint();

    DoublyLinkedList<std::string> strList;
    strList.push_back("Petr");
    strList.push_back("Sergeevich");
    strList.push_back("!");
    strList.pop_back();
    strList.print();
    std::cout << "reversed" << std::endl;
    strList.reversePrint();

    std::cout << "Spasibo" << std::endl;

    return 0;
}