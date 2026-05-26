#pragma once
#include "../Interface/Actor.h"
#include "../Item/Item.h"
#include <vector>

class Character;
class Inventory;

class Shop
{
private:
    std::vector<Item> Products;

public:
    Shop();

public:
    void OpenShop(Character& character, Inventory& inventory);
    void ShowProduct();

public:
    void Buy(int ProductIndex, Character& character, Inventory& inventory);
    void Sell(Character& character, Inventory& inventory);
};