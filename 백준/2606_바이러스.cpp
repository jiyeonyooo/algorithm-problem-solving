//1번과 연결 되어있는 노드의 개수

#include <stdio.h>
#include <iostream>

using namespace std;

int n, e, x, y;
int g[101][101];
int visited[101] = {0, };
int result = 0;

void dfs(int s) {
	for (int i = 1; i <= n; i++) {
		if (g[s][i] == 1 && visited[i] == 0) { //연결되어있는경우
			result++;
			visited[i] = 1;
			dfs(i);
		}
	}
	return;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> e;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = 0;
			g[i][j] = 0;
		}
	}

	visited[1] = 1;

	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}

	 dfs(1);
	 cout << result;

	return 0;
}