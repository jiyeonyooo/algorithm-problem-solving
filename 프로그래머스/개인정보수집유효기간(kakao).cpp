#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

bool check(string today, string start, int term) {
    int startY = stoi(start.substr(0, 4));
    int startM = stoi(start.substr(5, 2));
    int startD = stoi(start.substr(8, 2));
    int todayY = stoi(today.substr(0, 4));
    int todayM = stoi(today.substr(5, 2));
    int todayD = stoi(today.substr(8, 2));
    
    startM += term;
    startY += (startM - 1) / 12;
    startM = (startM - 1) % 12 + 1;
    
    startD -= 1;
    if (startD == 0) {
        startD = 28;
        startM -= 1;
        if (startM == 0) {
            startM = 12;
            startY -= 1;
        }
    }
    
    if (todayY > startY) return false;
    if (todayY == startY && todayM > startM) return false;
    if (todayY == startY && todayM == startM && todayD > startD) return false;

    return true;
    
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int termNum = terms.size();       //약관 개수
    int infoNum = privacies.size();   //개인정보 개수
    int termsArr[26] = {0, };
    
    for (int i = 0; i < termNum; i++) {
        int type = terms[i][0] - 'A';
        int term = stoi(terms[i].substr(2));
        termsArr[type] = term;
    }
    
    for (int i = 0; i < infoNum; i++) {
        if (!check(today, privacies[i].substr(0, 10), termsArr[privacies[i][11] - 'A'])) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
