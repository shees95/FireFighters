#include"Inventory.h"
#include <algorithm>
#include <iostream>

#include "../GameManager/GameManager.h"

using namespace std;

void Inventory::AddItem(Item item)            //inventory.addItem(hpPotion);
                                              //inventory.addItem(attackPotion);
{                                            
    items.push_back(item);

    cout << item.GetName()<< " 획득!" << endl;
}

bool Inventory::RemoveItem(Item item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].GetName() == item.GetName())
        {
            items.erase(items.begin() + i);
            cout << item.GetName() << " 을(를) 인벤토리에서 삭제!" << endl;
            return true;
        }
    }

    return false;
}

void Inventory::SortItemByPrice()
{
    sort(items.begin(), items.end(),
        [](const Item& a, const Item& b)
        {
            return a.GetPrice() < b.GetPrice();
        });

    cout << "인벤토리를 가격 '오름차순'으로 정렬!"
        << endl;
}

void Inventory::UseRandomItem(Character* character)
{
    if (items.empty())
    {
        cout << "인벤토리에 사용 가능한 아이템이 없습니다."
            << endl;

        return;
    }
    
    vector<int>UseType;
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].GetType() == ItemType::Use)
        {
            UseType.push_back(i);
        }
    }
    if (UseType.empty()) 
        {
            cout << "사용 가능한 아이템이 없습니다.\n"; return; 
        }
    int Random = rand() % UseType.size();
    int RandomIndex = UseType[Random];
    GameManager::GL.LogItemUse(items[RandomIndex]);
    cout << "랜덤으로 " << items[RandomIndex].GetName() << " 이(가) 사용됐습니다. " << endl;

    items[RandomIndex].Use(character);

    cout  << items[RandomIndex].GetName() << "이(가) 사용되어 인벤토리에서 사라집니다." << endl;;
   
    items.erase(items.begin() + RandomIndex);


}

void Inventory::PrintInventory()
{
    if (items.empty())
    {
        cout << "아이템이 없습니다.\n";
        return;
    }

    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". "
            << items[i].GetName() << "\t\t(기준가 : " <<items[i].GetPrice() <<"G)" << endl;
    }
}


void Inventory::PrintSellInventory()
{
    if (items.empty())
    {
        cout << "아이템이 없습니다.\n";
        return;
    }

    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". "
            << items[i].GetName()<< "\t\t(판매가 : " << items[i].GetSellPrice() << "G)" << endl;
    }
}

void Inventory::PrintUseItems()
{
    vector<int> UseType;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].GetType() == ItemType::Use)
        {
            UseType.push_back(i);
        }
    }

    if (UseType.empty())
    {
        cout << "사용 가능한 아이템이 없습니다." << endl;
        return;
    }

    cout << "[ 사용 가능한 아이템 ]" << endl;

    for (int i = 0; i < UseType.size(); i++)
    {
        int index = UseType[i];

        cout << i + 1 << ". "
            << items[index].GetName()
            << " "
            << items[index].GetPrice() << "G"
            << endl;
    }
}