#include "Item.h"

Item::Item(string Name, ItemType Type, int EffectType, int EffectValue, int Price)
    : Name(Name), Type(Type), EffectType(EffectType), EffectValue(EffectValue), Price(Price)
{ 
    //멤버 초기화 리스트로 생성자를 초기화하는 것과 생성자 본문에서 멤버 변수를 초기화 하는것의 차이
}

Item HpPotion("HP 포션", ItemType::Use, 0, 50, 100);              //HP포션 정의
Item PowerPotion("Power 포션", ItemType::Use, 1, 10, 200);        //Power포션 정의

void Item::Use(Actor* actor)
{
    switch (EffectType)
    {
    case 0:
        cout << Name << " 사용!" << endl;
        cout << "체력 " << EffectValue << " 회복!" << endl;
            // actor->Sethp(Gethp() + EffectValue);
        break;

    case 1:
        cout << Name << " 사용!" << endl;
        cout << "공격력 " << EffectValue << " 증가!" << endl;
        // actor->SetPower(actor->GetPower() + EffectValue);
        IsUsed = true;
        cout << "이번 전투 동안만 효과가 유지됩니다." << endl;

        // 이번 전투에만 효과 발휘를 구현못했음
        break;

    }
}

void Item::EndBattle(Actor* actor)
{
    if (IsUsed)
    {
        // actor->SetPower(actor->GetPower() - EffectValue);

        cout << "전투를 끝나며 버프가 종료되었습니다."
            << endl;

        IsUsed = false;
    }
}

