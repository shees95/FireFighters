#pragma once
#include <iostream>
#include <string>
#include "../Interface/Actor.h"


//- [ ]  아이템 사용 조건 : 자율
//-[]  아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영
//- []  아이템 : **체력 + 50(포션)또는 공격력 + 10 증가 * *
//-[]  체력 + 50(포션) : 현재 체력을 50 회복
//- []  공격력 + 10 : 해당 전투에만 효과 발휘
//- []  플레이어 캐릭터 : 전투 중 아이템 랜덤 사용 가능




using namespace std;

enum class ItemType
{
    Equip,
    Use,
    Etc
};



class Item : public Actor
{
private:
    string Name;

    ItemType Type;

    int EffectType;

    int EffectValue;

    int Price;


public:
    Item(string Name, ItemType Type, int EffectType, int EffectValue, int Price);

    
    void Use(Actor* actor);
    
    
    string GetName() { return Name; };
    int GetPrice() { return Price; };
};
