#include"Inventory.h"
#include <algorithm>

using namespace std;

void Inventory::AddItem(Item item)            //inventory.addItem(hpPotion);
                                              //inventory.addItem(attackPotion);
{                                             // 메인 함수에서 이걸로 추가가능
    items.push_back(item);

    cout << item.GetName()
        << " 획득!"
        << endl;
}

bool Inventory::RemoveItem(Item item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].GetName() == item.GetName())
        {
            items.erase(items.begin() + i);
            cout << item.GetName() << " 제거 완료!" << endl;
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

    cout << "가격 오름차순 정렬 완료!"
        << endl;
}

void Inventory::UseRandomItem(Actor* actor)
{
    {
        if (items.empty())
        {
            cout << "사용할 아이템이 없습니다."
                << endl;

            return;
        }

        int randomIndex = rand() % items.size();

        cout << items[randomIndex].GetName()
            << " 랜덤 사용!"
            << endl;

        items[randomIndex].Use(actor);

        cout << items[randomIndex].GetName() << "이 인벤토리에서 사용되었습니다." << endl;;
       
        items.erase(items.begin() + randomIndex);


    }
}