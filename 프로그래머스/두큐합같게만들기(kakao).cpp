#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    //각 큐의 원소의 합을 나타내는 변수
    long long s1 = 0;
    long long s2 = 0;
    //각 큐의 맨 앞 원소를 가리키는 index
    int f1 = 0;
    int f2 = 0;
    int maxNum = queue1.size() * 2 + 10;
    
    for (int i = 0; i < queue1.size(); i++) {
        s1 += queue1[i];
        s2 += queue2[i];
    }
    
    if ((s1 + s2) % 2 == 1) {
        answer = -1;
        return answer;
    }
    
    while (f1 != queue1.size() && f2 != queue2.size() && answer <= maxNum) {
        if (s1 == s2) return answer;
        else if (s1 > s2) {
            queue2.push_back(queue1[f1]);
            s1 -= queue1[f1];
            s2 += queue1[f1];
            f1++; answer++;
        }
        else if (s1 < s2) {
            queue1.push_back(queue2[f2]);
            s1 += queue2[f2];
            s2 -= queue2[f2];
            f2++; answer++;
        }
    }
    
    answer = -1; //같아질 수 없는 경우
    return answer;
}
