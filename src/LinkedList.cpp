#include "../Main.hpp"
using namespace std;

LinkedList::LinkedList() : first{}
{
}

void LinkedList::addItem(std::string item)
{
    if(first == nullptr)
    {
        first.reset(new ListItem{item});
    }
    else
    {
    shared_ptr<ListItem> iter{first};
    while(iter->next != nullptr)
    {
        iter = iter->next;
    }
    iter->next.reset(new ListItem{item});
    }
}

void LinkedList::addItem(std::string item, unsigned int previousIndex)
{
    shared_ptr<ListItem> iter{first}, iter2{};
    for(unsigned int i = 0; i < previousIndex; i++)
    {
        if(iter->next == nullptr)
        {
            cerr << "Error: Index " << previousIndex << " for LinkedList::addItem(string, unsigned int) out of range." << endl;
            return;
        }
        iter = iter->next;
    }
    iter2 = iter->next;
    iter->next.reset(new ListItem{item});
    iter->next->next = iter2;
}

std::string LinkedList::searchItem(unsigned int index)
{
    shared_ptr<ListItem> iter{first};
    for(unsigned int i = 0; i < index; i++)
    {
        if(iter->next == nullptr)
        {
            cerr << "Error: Index " << index << " for LinkedList::searchItem(unsigned int) out of range." << endl;
            return "";
        }
        iter = iter->next;
    }
    return iter->value;
}

void LinkedList::removeItem(unsigned int index)
{
    shared_ptr<ListItem> iter{first}, iter2{};
    if(index == 0)
    {
        iter = iter->next;
        first.reset();
        first = iter;
    }
    else
    {
        for(unsigned int i = 0; i < index - 1; i++)
        {
            if(iter->next == nullptr)
            {
                cerr << "Error: Index " << index << " for LinkedList::searchItem(unsigned int) out of range." << endl;
                return;
            }
            iter = iter->next;
        }
        iter2 = iter->next->next;
        iter->next.reset();
        iter->next = iter2;
    }
}

LinkedList::~LinkedList()
{
    shared_ptr<ListItem> iter{first};
    while(iter != nullptr)
    {
        iter = iter->next;
        iter.reset();
    }
}
