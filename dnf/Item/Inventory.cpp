#include"Inventory.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Inventory::AddItem(Item item)            //inventory.addItem(hpPotion);
                                              //inventory.addItem(attackPotion);
{                                             // ���� �Լ����� �̰ɷ� �߰�����
    items.push_back(item);

    cout << item.GetName()<< " ȹ��!" << endl;
}

bool Inventory::RemoveItem(Item item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].GetName() == item.GetName())
        {
            items.erase(items.begin() + i);
            cout << item.GetName() << " ���� �Ϸ�!" << endl;
            return true;
        }
    }

    return false;
}

void Inventory::SortItemByPrice()
{
    sort(items.begin(), items.end(),
        [](Item a, Item b)
        {
            return a.GetPrice() < b.GetPrice();
        });

    cout << "���� �������� ���� �Ϸ�!"
        << endl;
}

void Inventory::UseRandomItem(Actor* actor)
{
    {
        if (items.empty())
        {
            cout << "����� �������� �����ϴ�."
                << endl;

            return;
        }

        int randomIndex = rand() % items.size();

        cout << items[randomIndex].GetName()
            << " ���� ���!"
            << endl;

        items[randomIndex].Use(actor);

        cout << items[randomIndex].GetName() << "�� �κ��丮���� ���Ǿ����ϴ�." << endl;;
       
        items.erase(items.begin() + randomIndex);


    }
}