#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char select(char a, char b, int *result) {
    int aidx = a - 'A';
    int bidx = b - 'A';
    if (result[aidx] > result[bidx]) return a;
    else if (result[aidx] < result[bidx]) return b;
    else if (result[aidx] == result[bidx]) return a < b ? a : b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    int result[26] = {0, };
    int idx;
    for (int i = 0; i < n; i++) {
        if (choices[i] == 4) continue;
        else if (choices[i] < 4) { //앞의 캐릭터가 점수 획득
            idx = survey[i][0] - 'A';
            result[idx] += (4 - choices[i]);
        }
        else if (choices[i] > 4) { //뒤의 캐릭터가 점수 획득
            idx = survey[i][1] - 'A';
            result[idx] += (choices[i] - 4);
        }
    }
    
    answer.push_back(select('R', 'T', result));
    answer.push_back(select('C', 'F', result));
    answer.push_back(select('J', 'M', result));
    answer.push_back(select('A', 'N', result));
    
    return answer;
}
