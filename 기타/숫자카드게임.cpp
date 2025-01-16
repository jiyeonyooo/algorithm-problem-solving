//
//  숫자카드게임.cpp
//
//  Created by 유지연 on 1/8/25.
//
// [이것이 코딩테스트다] 2019 국가 교육기관 코딩 테스트

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "include/numberCardGame.hpp"

int numberCardGame() {
    int row, column;
    std::cout << "행과 열의 개수를 차례로 입력해주세요: ";
    std::cin >> row >> column;
    
    int min = 10001;
    int max = 0;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int temp;
            std::cin >> temp;
            if (temp < min) min = temp;
        }
        if (max < min) max= min;
        min = 10001;
    }
    std::cout << "가장 큰 수는 " << max << "입니다!\n";
    
    return max;
}

