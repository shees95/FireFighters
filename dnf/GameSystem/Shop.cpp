#include <iostream>

using namespace std;

#include "../Item/Inventory.h"
#include "../Item/Item.h"
#include "Shop.h"
#include "../Character/Character.h"

Shop::Shop()
{
	Products.push_back(Item("HP 포션", ItemType::Use, 0, 50, 100));
	Products.push_back(Item("Power 포션", ItemType::Use, 1, 10, 200));
}

void Shop::OpenShop(Character& character)
{
	while (true)
	{
		int choice = 0;
		// 상점 메뉴 출력
		cout << endl
			<< "----------------------" << endl
			<< "  상점에 어서오세요!" << endl
			<< "----------------------" << endl
			<< "1. 구매" << endl
			<< "2. 판매" << endl
			<< "0. 나가기" << endl
			<< "선택 :";

		cin >> choice;

		//상점 메뉴 선택
		switch (choice)
		{
		case 1:
		{
			ShowProduct();

			int ProductIndex;

			cout << endl << " 구매할 상품의 번호를 입력해주세요." << endl
				<< "선택 :";
			cin >> ProductIndex;
			cout << endl;

			Buy(ProductIndex, character);

			break;
		}
		case 2:
		{
			Sell(character);
			break;
		}
		case 0:
		{
			cout << "상점을 나갑니다." << endl;
			return;
		}

		default:
		{
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		}
	}
}

void Shop::ShowProduct()
{
	//번호를 매기며 모든 상품의 이름과 가격 표시
	cout << endl 
		<< "------------------" << endl
		<< " 판매 상품 리스트" << endl
		<< "------------------" << endl;

	for (size_t i = 0; i < Products.size(); i++)
	{
		cout << i + 1 << "." << Products[i].GetName() << " - 가격 : " << Products[i].GetPrice() << "골드" << endl;
	}
	cout << "0. 나가기" << endl;
}


void Shop::Buy(int ProductIndex, Character& character)
{
	int Index = ProductIndex - 1;

	//0. 나가기 구현
	if (ProductIndex == 0)
	{
		return;
	}

	// 번호 잘못 입력했을 때 처리
	if (Index < 0 || Index >= static_cast<int>(Products.size()))
	{
		cout << "잘못된 상품 번호입니다." << endl;
		return;
	}

	Item item = Products[Index];

	// 골드 부족
	if (character.GetGold() < item.GetPrice())
	{
		cout << "골드가 부족합니다!" << endl;
		return;
	}

	// 골드 차감
	character.SetGold(character.GetGold() - item.GetPrice());

	//아이템 지급
	character.GetInventory().AddItem(item);

	cout << "남은 골드 : " << character.GetGold() << "G" << endl;
}

void Shop::Sell(Character& character)
{
	Inventory& inventory = character.GetInventory();

	while (true)
	{
		cout << endl
			 << "------------------" << endl
			 << " 판매 메뉴 " << endl
			 << "------------------" << endl;

		// 인벤토리 출력
		inventory.PrintInventory();
		cout << "0. 나가기" << endl;

		// 인벤토리가 비어있으면 종료
		if (inventory.GetInventorySize() == 0)
		{
			cout << "보유한 아이템이 없습니다." << endl;
			return;
		}

		// 판매 아이템 선택
		int SellIndex;
		cout << endl
			<< "판매할 아이템 번호 입력"
			<< endl
			<< "선택 : ";

		cin >> SellIndex;
		int Index = SellIndex - 1;

		//0.나가기 구현
		if (SellIndex == 0)
		{
			return;
		}

		//번호 잘못 입력했을 때 처리
		if (Index < 0 || Index >= static_cast<int>(inventory.GetInventorySize()))
		{
			cout << "잘못된 번호입니다." << endl;
			continue;
		}

		// 아이템 가져오기
		Item item = inventory.GetItem(Index);

		// 판매 가격
		int SellPrice = item.GetPrice() * 60 / 100;

		// 골드 지급
		character.SetGold(character.GetGold() + SellPrice);

		// 인벤토리 제거
		inventory.RemoveItem(item);

		cout << endl
		     << item.GetName() << " 판매 완료!" << endl;

		cout << SellPrice << " 골드 획득!" << " (현재 골드 : " << character.GetGold() << "G)" << endl;
	}
}