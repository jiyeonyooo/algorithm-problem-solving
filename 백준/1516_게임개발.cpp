#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c;
int cost[501];
int result[501] = {0, };
vector<int> adjList[501];
vector<int> rn; //root node

void dfs(int root, int c) {
	result[root] = c;
	for (int child: adjList[root]) {
		if (result[child] == 0) dfs(child, result[root] + cost[child]);
		else if (result[root] + cost[child] > result[child]) {
			dfs(child, result[root] + cost[child]);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> cost[i];
		int j = 0;
		for(;;) {
			cin >> m;
			if (m == -1 && j == 0) {
				rn.push_back(i);
				break;
			}
			else if (m == -1) break;
			else {
				adjList[m].push_back(i);
				j++;
			}
		}
	}

	for (int root: rn) dfs(root, cost[root]);

	for (int i=1; i<=n; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
