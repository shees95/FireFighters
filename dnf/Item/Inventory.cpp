#include"Inventory.h"
#include <algorithm>
#include <iostream>

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

void Inventory::UseRandomItem(Actor* actor)
{
    {
        if (items.empty())
        {
            cout << "인벤토리에 사용 가능한 아이템이 없습니다."
                << endl;

            return;
        }

        int randomIndex = rand() % items.size();

        cout << "랜덤으로 " << items[randomIndex].GetName() << " 이(가) 사용됐습니다. " << endl;

        items[randomIndex].Use(actor);

        cout  << items[randomIndex].GetName() << "이(가) 사용되어 인벤토리에서 사라집니다." << endl;;
       
        items.erase(items.begin() + randomIndex);


    }
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
            << items[i].GetName()
            << endl;
    }
}

