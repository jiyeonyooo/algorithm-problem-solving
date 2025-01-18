//
//  maxSum.cpp
//
//  Created by 유지연 on 1/7/25.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "include/maxSum.hpp"


int maxSum(int n, int m, int k, std::vector<int> v){
    int result = 0;
    sort(v.begin(), v.end()); //vector 오름차순 정리
    //maxSum을 구할 때에는 가장 큰 값과 그 다음으로 큰 값만 사용됨, 나머지는 필요 X
    int first = v[n-1];
    int second = v[n-2];
    
    int i = 0;
    int j = 0;
    while (i < m) {
        if (j < k) result += first;
        else if (j >= k and j < 2*k) result += second;
        i++;
        if (j == 2*k - 1) j = 0;
        else j++;
    }

    return result;
}

/*int main(int argc, const char * argv[]) {
    int n, m, k;
    std::vector<int> v;
    std::cout << "n, m, k를 입력해주세요: ";
    std::cin >> n >> m >> k;
    std::cout << "숫자 배열을 입력해주세요: ";
     
    for (int i=0; i<n; i++) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    
    int result = maxSum(n, m, k, v);
    std::cout << result << "\n";
    return 0;
}*/

