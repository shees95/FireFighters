// Util.cpp

#include <iostream>

#include "Util.h"

using namespace std;

int Util::SelectorInt(int min, int max)
{
    int input;
    while (true)
    {
        cout << "선택하세요. (" << min << "~" << max << ") : ";
        cin >> input;

        if (cin.fail())  // 숫자가 아닌 입력 처리
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "숫자를 입력해주세요.\n";
            continue;
        }

        if (input >= min && input <= max)
            return input;  // 유효한 입력

        cout << "유효하지 않은 입력입니다. 올바른 번호를 입력하세요.\n";
    }
}

bool Util::SelectorBool()
{
    string input;
    while (true)
    {
        cout << "(y/n) : ";
        cin >> input;

        if (input == "y" || input == "Y") return true;
        if (input == "n" || input == "N") return false;

        cout << "y 또는 n 을 입력해주세요.\n";
    }
}

std::string Util::SelectorString(std::string& prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        cin >> input;

        if (input.empty())
        {
            cout << "입력값이 없습니다.\n";
            continue;
        }

        bool onlyDigits = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                onlyDigits = false;
                break;
            }
        }
        if (onlyDigits)
        {
            cout << "문자를 포함해주세요.\n";
            continue;
        }

        return input;  // 유효한 입력
    }
}