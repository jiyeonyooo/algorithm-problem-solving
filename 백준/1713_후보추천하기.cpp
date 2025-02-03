#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first == b.second.first) return a.second.second > b.second.second;
    else return a.second.first > b.second.first;
}

int main() {
    int num, total, student;
    vector<pair<int, pair<int, int>>> candidates; //(학생 번호, (추천수, 게시시기))
    bool existed = false;
    cin >> num >> total;

    for (int i = 0; i < total; i++) {
        cin >> student;

        for (int j = 0; j < candidates.size(); j++) {
            if (student == candidates[j].first) {
                candidates[j].second.first++; //후보에 이미 있는 경우
                //cout << "이미 존재하는 후보\n";
                existed = true;
                break;
            }
        }

        if (!existed) { //기존 후보에 없는 경우
            if (candidates.size() == num) { //꽉차서 삭제해야 하는 경우
                //cout << "삭제: " << candidates.back().first << "\n";
                candidates.pop_back();
            }
            //cout << "삽입: " << student << "\n";
            candidates.push_back(make_pair(student, make_pair(1, i)));
        }

        existed = false;
        sort(candidates.begin(), candidates.end(), cmp);

    }

    //최종 결과 학생번호 오름차순 정렬
    sort(candidates.begin(), candidates.end());

    //for (auto i : candidates) cout << "학생 번호: "<< i.first <<  "추천수: " << i.second.first << "\n";
    for (auto i : candidates) cout << i.first << " ";

    return 0;
}
