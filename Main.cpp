#include "Main.hpp"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    shared_ptr<LinkedList> list1{new LinkedList{}};
    string input{};
    cin >> input;
    list1->addItem(input);
    cin >> input;
    list1->addItem(input);
    cin >> input;
    list1->addItem(input);
    cin >> input;
    list1->addItem(input, 1);
    cout << "0: " << list1->searchItem(0) << endl << "1: " << list1->searchItem(1) << endl << "2: " << list1->searchItem(2) << endl << "3: " << list1->searchItem(3) << endl;
    cin >> input;
}
