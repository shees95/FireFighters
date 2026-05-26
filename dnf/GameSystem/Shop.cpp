#include <iostream>
#include <vector>
#include <string>

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
void Shop::OpenShop(Character& character, Inventory& inventory)
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

			Buy(ProductIndex, character, inventory);

			break;
		}
		case 2:
		{
			Sell(character, inventory);
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

	for (int i = 0; i < Products.size(); i++)
	{
		cout << i + 1 << "." << Products[i].GetName() << " - 가격 : " << Products[i].GetPrice() << "골드" << endl;
	}
}


void Shop::Buy(int ProductIndex, Character& character, Inventory& inventory)
{
	int Index = ProductIndex - 1;

	if (Index < 0 || Index >= Products.size())
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
	inventory.AddItem(item);

	cout << "남은 골드 : " << character.GetGold() << "G" << endl;
}

void Shop::Sell(Character& character, Inventory& inventory)
{
	cout << "아직 개발중인 기능입니다." << endl;
}