// Util.h

#pragma once
#include <string>

namespace Util
{
    // 범위 내 정수 입력 받기
    int SelectorInt(int min, int max);

    // 예/아니오 입력 받기
    bool SelectorBool();

    // 문자열 입력 받기 (유효성 검사 포함)
    std::string SelectorString(const std::string& prompt);
}