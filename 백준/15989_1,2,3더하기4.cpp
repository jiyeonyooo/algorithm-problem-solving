#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc, n;	
	int max = -1;
	int d[10001];
	int num[10001];
	cin >> tc;

	for (int i = 0; i < 10001; i++) d[i] = 1;

	for (int i = 0; i < tc; i++) {
		cin >> num[i];
		if (num[i] > max) max = num[i];
	}

	for (int i = 2; i <= 3; i++) {
		for (int j = i; j <= max; j++) d[j] += d[j-i];
	}

	for (int i = 0; i < tc; i++) {
		cout << d[num[i]] << "\n";
	}

	return 0;
}