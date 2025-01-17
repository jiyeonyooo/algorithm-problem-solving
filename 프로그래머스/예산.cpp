//
//  예산.cpp
//
//  Created by 유지연 on 1/7/25.
//

/*
[문제출처] https://school.programmers.co.kr/learn/courses/30/lessons/12982
프로그래머스 Lv1. 예산 Summer/Winter Coding(~2018)
*/

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#include "include/budget.hpp"

int budget(std::vector<int> d, int budget) {
    int answer = 0;
    int given = 0; //지급된 금액
    
    sort(d.begin(), d.end()); //신청 금액 오름차순 정리
    
    for(int i=0; i<d.size(); i++){
        given += d[i]; //요청금액이 작은 순으로(greedy) 지급액에 더함
        if (given <= budget) answer++; //더했을 때의 값이 budget을 초과하지 않으면 ok
        else break;
    }
    
    return answer;
}

