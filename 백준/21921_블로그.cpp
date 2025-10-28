/*
N개의 정수 중 연속된 X개를 묶었을 떄의 최댓값 = 최대 방문자수
해당 최대 방문자수가 나오는 묵음의 개쑤 = 최종 결과값 
N의 최댓값 250,000 / 방문자수 최댓값 8,000
최대 방문자수의 최댓값 = 20억 -> int 범위 내에서 처리 가능
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int n, x, result;
	int maxVisit = -1;
	int visit[250001] = {0, };
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> visit[i];
		visit[i] += visit[i-1]; //누적합
	}

	for (int i = x; i <= n; i++) {
		if (visit[i] - visit[i-x] > maxVisit) {
			maxVisit = visit[i] - visit[i-x];
			result = 1;
		}
		else if (visit[i] - visit[i-x] == maxVisit) result ++;
	}

	if (maxVisit == 0) cout << "SAD";
	else cout << maxVisit << "\n" << result;

	return 0;
}