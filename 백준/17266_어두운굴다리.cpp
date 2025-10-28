/*
동일 높이의 M개의 가로등을 위치 x에 배치
이 때 0 ~ N 까지의 길이를 모두 커버 필요
1개의 가로등이 커버할 수 있는 구간: x-H ~ x+H
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k, diff, pre;
	cin >> n >> m >> pre;
	diff = pre;

	for (int i = 1; i < m; i++) {
		cin >> k;
		if ((k - pre) / 2 + (k - pre) % 2 > diff) diff = (k - pre) / 2 + (k - pre) % 2;
		pre = k;
	}
	if (n - pre > diff) diff = n - pre;
	
	cout << diff;

	return 0;
}