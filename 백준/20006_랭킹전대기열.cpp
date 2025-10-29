/*
한 방에 들어올 수 있는 사용자의 레벨 = 처음 들어온 사용자의 레벨 +- 10
한 방 -> [0] ~ [m-1], [m] ~ [2m-1], [2m] ~ [3m-1]
열려있는 방이 하나도 없는 경우 -> 방 새로 생성
열려있는 방 중 매칭되는 것이 하나도 없는 경우 -> 방 새로 생성
열려있는 방 중 매칭되는 것이 있는 경우 -> 배열에 삽입
출력 시 방별로 사전 순 정렬
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, string> pis;

bool cmp (pis a, pis b) {
	return a.second < b.second;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int p, m, level;
	int openedRoom = 0; //현재 열려있는 방의 개수
	string name;
	pis room[91000];
	int full[300] = {0, };
	cin >> p >> m;

	for (int i = 0; i < p; i++) {
		cin >> level >> name;
		pis user = make_pair(level, name); //방을 찾고 있는 유저
		bool insert = false; //해당 유저의 삽입 여부

		for (int j = 0; j < openedRoom; j++) {
			int minLimit = room[j * m].first - 10;
			int maxLimit = room[j * m].first + 10;
			if (minLimit <= level && level <= maxLimit && full[j] < m) {
				room[j * m + full[j]] = user;
				full[j]++;
				insert = true; //삽입 완료
				break;
			}
		}
		if (!insert) {
			room[openedRoom * m] = user;
			full[openedRoom++]++;
		}
	}

	for (int i = 0; i < openedRoom; i++) {
		if (full[i] == m) cout << "Started!\n";
		else cout << "Waiting!\n";

		int s = i * m;
		sort(room + s, room + (s + full[i]), cmp); //해당 방의 유저 닉네임 오름차순 정렬

		for (int j = 0; j < full[i]; j++) cout << room[s + j].first << " " << room[s + j].second << "\n";
	}

	return 0;
}