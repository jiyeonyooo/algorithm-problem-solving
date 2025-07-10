#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int nums[100001];
int finds[100001];
int n, m;

int bsearch(int find) {
	int l = 0; 
	int r = n - 1;
	int m;
	int result = 0;

	while (l <= r) {
		m = (l + r) / 2;
		if (find == nums[m]) {
			result = 1;
			break;
		}
		else if (find < nums[m]) r = m - 1;
		else if (find > nums[m]) l = m + 1; 
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; //찾을 대상 배열
	for (int i=0; i<n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+n);

	cin >> m; //찾아야 하는 수들의 배열
	for (int i=0; i<m; i++) cin >> finds[i];
	for (int i=0; i<m; i++) cout << bsearch(finds[i]) << "\n";
 
	//존재: 1, 존재X: 0

	return 0;
}