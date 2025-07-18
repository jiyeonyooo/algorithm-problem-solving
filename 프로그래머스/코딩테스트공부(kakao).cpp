#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int d[151][151];
    int num = problems.size(); //전체 문제 개수
    int maxAlp = alp;
    int maxCop = cop;
    
    for (int i = 0; i < num; i++) {
        if (problems[i][0] > maxAlp) maxAlp = problems[i][0]; //최대 알고력
        if (problems[i][1] > maxCop) maxCop = problems[i][1]; //최대 코딩력
    }
    
    //cout << "최대 알고력: " << maxAlp << ", 최대 코딩력: " << maxCop << "\n";
    
    for (int i = alp; i <= maxAlp; i++) {
        for (int j = cop; j <= maxCop;  j++) d[i][j] = 1e9;
    }
    d[alp][cop] = 0; //시작값
    
    for (int i = alp; i <= maxAlp; i++) {
        for (int j = cop; j <= maxCop; j++) {
            if (i < maxAlp) d[i+1][j] = min(d[i+1][j], d[i][j] + 1);
            if (j < maxCop) d[i][j+1] = min(d[i][j+1], d[i][j] + 1);
            for (int k = 0; k < num; k++) {
                if (i >= problems[k][0] && j >= problems[k][1]) {
                    int alp_rwd = problems[k][2];
                    int cop_rwd = problems[k][3];
                    int cost = problems[k][4];
                    int ni = min(i+alp_rwd, maxAlp);
                    int nj = min(j+cop_rwd, maxCop);
                    d[ni][nj] = min(d[ni][nj], d[i][j] + cost);
                }
            }
        }
    }
    
    answer = d[maxAlp][maxCop];
    
    return answer;
}
