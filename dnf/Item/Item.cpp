#include "Item.h"
#include "../Character/Character.h"
#include <iostream>

using namespace std;

Item::Item(std::string Name, ItemType Type, int EffectType, int EffectValue, int Price)
    : Name(Name), Type(Type), EffectType(EffectType), EffectValue(EffectValue), Price(Price)
{ 
    //멤버 초기화 리스트로 생성자를 초기화하는 것과 생성자 본문에서 멤버 변수를 초기화 하는것의 차이
}

Item HpPotion("HP 포션", ItemType::Use, 0, 50, 100);              //HP포션 정의
Item PowerPotion("Power 포션", ItemType::Use, 1, 10, 200);        //Power포션 정의

void Item::Use(Character* character)
{
    switch (EffectType)
    {
    case 0:
        cout << Name << " 사용!" << endl;
        cout << "체력 " << EffectValue << " 회복!" << endl;
        character->SetHealth(character->GetHealth() + EffectValue);
        break;

    case 1:
        cout << Name << " 사용!" << endl;
        cout << "공격력 " << EffectValue << " 증가!" << endl;
        character->SetTempPower(character->GetTempPower() + EffectValue);
        cout << "이번 전투 동안만 효과가 유지됩니다." << endl;
        break;
    }
}

