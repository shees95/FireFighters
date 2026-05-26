#pragma once
#include "../Interface/Actor.h"
#include "../Item/Item.h"
#include "../Character/Character.h"

#include <vector>
#include <string>
using namespace std;

class character;
class Inventory;

class Shop
{
private:
    vector<Item> Products;

public:
    Shop();

public:
    void OpenShop(Character& character, Inventory& inventory);

    void ShowProduct();

    void Buy(int ProductIndex, Character& character, Inventory& inventory);
    void Sell(Character& character, Inventory& inventory);



};