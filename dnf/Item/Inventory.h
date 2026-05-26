#pragma once

#include <vector>
#include "Item.h"



class Inventory
{

public:
    void AddItem(Item item);

    bool RemoveItem(Item item);

    Item GetItem(int index) { return items[index]; };

    void SortItemByPrice();

    void UseRandomItem(Actor* actor);



private:
    vector<Item> items;

};