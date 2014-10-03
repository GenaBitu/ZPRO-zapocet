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
    list1->addItem(input, 0);
    cout << list1->searchItem(0) << endl << list1->searchItem(1) << endl << list1->searchItem(2) << endl;
    cin >> input;
}
