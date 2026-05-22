#pragma once

#include <algorithm>
#include <vector>
#include "Item.h"

using namespace std;

class Inventory
{
private:
	vector<Item> items;

public:
    void AddItem(Item item);

    bool RemoveItem(Item item);

    Item GetItem(int index) {return items[index];};

    void SortItemByPrice();

    void UseRandomItem(Actor* actor);
};