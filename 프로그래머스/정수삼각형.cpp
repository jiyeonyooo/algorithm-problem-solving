//
//  정수삼각형.cpp
//
//  Created by 유지연 on 1/15/25.
//
// Dynamic Programming Bottom Up

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int top = triangle[0][0];
    int depth = triangle.size();
    vector<vector<int>> sum = triangle;
    //index [a][b] >> 부모: index[a-1][b-1] or [a-1][b] (depth의 양끝은 제외)
    
    sum[1][0] += top;
    sum[1][1] += top;
    
    for (int i=2; i<depth; i++) {
        for (int j=0; j<i+1; j++) {
            if (j == 0) sum[i][j] += sum[i-1][j]; //most left node
            else if (j == i) sum[i][j] += sum[i-1][j-1]; //most right node
            else sum[i][j] += max(sum[i-1][j-1], sum[i-1][j]);
        }
    }
    
    sort(sum[depth-1].begin(), sum[depth-1].end());
    //경로의 합 중 가장 큰 것 선택
    answer = sum[depth-1][depth-1];
    
    return answer;
}
