#pragma once
#include "../Interface/Actor.h"
#include "../Item/Item.h"
#include <vector>

class Character;

class Shop
{
private:
    std::vector<Item> Products;

public:
    Shop();

public:
    void OpenShop(Character& character);
    void ShowProduct();

public:
    void Buy(int ProductIndex, Character& character);
    void Sell(Character& character);
};