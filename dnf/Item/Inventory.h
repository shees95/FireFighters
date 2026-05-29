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

    void UseRandomItem(Character* character);

    void PrintInventory();
    void PrintSellInventory();
    
    std::size_t GetInventorySize() const { return items.size(); };

    void PrintUseItems();

private:
    std::vector<Item> items;

};