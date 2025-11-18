/*
총 인원 N명 (0 이상)
상위 P개의 점수 -> 랭킹
태수는 몇 등일지? -> P등 안에 들지 못하면 -1 출력
*/


#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int total, taesu, limit, result, num;
	int same = 0;
	cin >> total >> taesu >> limit;
	result = 1;

	for (int i = 0; i < total; i++) {
		cin >> num;
		if(num > taesu) result++;
		if (num == taesu) same++;

		if (result > limit) {
			cout << -1;
			return 0;
		}
	}

	if(result + same > limit) cout << -1;
	else cout << result;

	return 0;
}