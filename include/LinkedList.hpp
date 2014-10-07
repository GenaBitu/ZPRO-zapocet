#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList
{
    #include "ListItem.hpp"
    public:
        LinkedList();
        explicit LinkedList(std::string filename);
        void addItem(std::string item);
        void addItem(std::string item, unsigned int previousIndex);
        std::string searchItem(unsigned int index);
        void removeItem(unsigned int index);
        void exporter(std::string filename);
        ~LinkedList();
    private:
        std::shared_ptr<ListItem> first;
};

#endif // LINKEDLIST_HPP
