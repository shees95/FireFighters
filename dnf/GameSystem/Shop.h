#pragma once
#include "../Interface/Actor.h"

#include <vector>
#include <string>
using namespace std;


class Inventory;

struct Product
{
    string Name;
    int Price;
};

class Shop
{
private:
    vector<Product> Products;

public:
    Shop();

public:
    void OpenShop(Inventory& Inventory);

    void ShowProduct();

    void Buy(int ProductIndex, Inventory& Inventory);
    void Sell();



};