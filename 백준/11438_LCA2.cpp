#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> adjList[100001];
int parent[18][100001];
int depth[100001];

//parent와 depth 값 계산
void dfs(int a, int p, int d) {
	depth[a] = d;
	parent[0][a] = p;

	for (int next: adjList[a]) {
		if (next == p) continue; //양방향으로 저장해줬기 때문에 처리해줘야 함
		dfs(next, a, d+1);
	}

	return;
}

int lca(int a, int b) {

	if (depth[a] < depth[b]) swap(a, b); //a가 더 아래 노드로 설정
	
	//두 노드의 높이가 같아지도록 a 조정
	for (int i=17; i>=0; i--) {
		if (depth[a]-depth[b] >= (1 << i)) a = parent[i][a];
	}

	int result = -1;

	if (a == b) return a;
	
	//위에서부터 공통 조상 확인, 다르면 a, b 위치 이동
	for (int i=17; i>=0; i--) {
		if (parent[i][a] == parent[i][b]) {
			result = parent[i][a];
			continue;
		}
		else {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n; //정점 개수
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		adjList[a].push_back(b); // a -> b
		adjList[b].push_back(a); // b -> a
		//내 맘대로 부모 정하지 말고 문제에서 조건 안주면 양방향으로 저장하자!
	}

	dfs(1, 0, 0); //root의 parent = 0, depth = 0 설정

	//parent 배열 채우기
	for (int i=1; i<=17; i++) {
		for (int j=1; j<=n; j++) {
			parent[i][j] =parent[i-1][parent[i-1][j]]; 
		}
	}

	cin >> m; //공통 조상을 구할 정점
	for (int i=1; i<=m; i++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}