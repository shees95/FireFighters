#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "../Character/Inventory.h"
#include "../Item/Item.h"
#include "Shop.h"

Shop::Shop()
{
	Products.push_back({ "HP 포션", 5 });
	Products.push_back({ "공격력 포션", 10 });
}

void Shop::OpenShop(Inventory& Inventory)
{
	int choice = 0;
	cout << "----------------------" << endl
		<< "  상점에 어서오세요!" << endl
		<< "----------------------" << endl
		<< "1. 구매" << endl
		<< "2. 판매" << endl
		<< "0. 나가기" << endl
		<< "선택 :";
	cin >> choice;

	switch (choice)
	{
	case 1:
		ShowProduct();

		int ProductIndex;
		cin >> ProductIndex;
		cout << endl << " 구매할 상품을 입력해주세요." << endl
			<< "선택 :";

		//Buy(ProductIndex, inventory)

		break;
	case 2:
		break;

	case 0:
		cout << "상점을 나갑니다." << endl;
		break;
	}
}

void Shop::ShowProduct()
{
	//번호를 매기며 모든 상품의 이름과 가격 표시
	for (int i = 0; i < Products.size(); i++)
	{
		cout << i + 1 << "." << Products[i].Name << "  -- 가격 : " << Products[i].Price << "골드" << endl;
	}
}


void Shop::Buy(int ProductIndex, Inventory& inventory)
{
	int Index = ProductIndex - 1;

	if (Index < 0 || Index >= Products.size())
	{
		cout << " 잘못된 상품 번호 입니다." << endl;
		return;
	}

	//Item item;
	//item.SetName(Products[Index].Name);
	//inventory.AddItem(item);


	//cout << item.GetName() << " 구매 완료!" << endl;
}

void Shop::Sell()
{
}