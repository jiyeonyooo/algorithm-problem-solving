//
//  fibonacci.cpp
//
//  Created by 유지연 on 1/15/25.
//

#include "fibonacci.hpp"
#include <vector>
#include <iostream>

//Recursion 단순 재귀 이용 -> O(2^n)
int fibo(int n) {
    if (n==1 || n==2) return 1;
    return fibo(n-1) + fibo(n-2);
}

//Dynamic Programming TopDown 방식 사용
unsigned long long fiboTopDown(int n, std::vector<unsigned long long> &dpTable) {
    if (n==1 || n==2) return 1;
    if (dpTable[n] != 0) {
        std::cout << dpTable[n] << "\n";
        return dpTable[n];
    }
    dpTable[n] = fiboTopDown(n-1, dpTable) + fiboTopDown(n-2, dpTable);
    return dpTable[n];

}

//Dynamic Programming BottomUp 방식 사용
unsigned long long fiboBottomUp(int n, std::vector<unsigned long long> &dpTable) {
    dpTable[1] = 1;
    dpTable[2] = 1;
    int m = 3;
    while (m != n + 1) {
        dpTable[m] = dpTable[m-1] + dpTable[m-2];
        m++;
    }
    return dpTable[n];
}
