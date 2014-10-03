#ifndef LISTITEM_HPP
#define LISTITEM_HPP
#include "Libs.hpp"


class ListItem
{
public:
    friend LinkedList;
    ListItem() = delete;
    ListItem(std::string item);
    std::string value;
    std::shared_ptr<ListItem> next;
};

#endif // LISTITEM_HPP
