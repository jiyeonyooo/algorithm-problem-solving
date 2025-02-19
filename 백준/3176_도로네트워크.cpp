#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int n, k;
int a, b, c;
vector<pii> adjList[100001];
int parent[18][100001];
int mincost [18][100001];
int maxcost [18][100001];
int depth[100001];

void dfs (int a, int p, int d, int c) {
	depth[a] = d;
	parent[0][a] = p;
    mincost[0][a] = c;
    maxcost[0][a] = c;

	for (pii next: adjList[a]) {
		if (next.first == p) continue;
		dfs(next.first, a, d+1, next.second);
	}

    return;
}

int lca(int a, int b) {

	if (depth[a] < depth[b]) swap(a,b);

	for (int i=17; i>=0; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
            a = parent[i][a];
        }
	}

	if (a == b) return a;

	int result = -1; //lca

	for (int i=17; i>=0; i--) {
		if (parent[i][a] == parent[i][b]) {
			result = parent[i][a];
			continue;
		} else {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return result;

}

pii minmax(int a, int b, int p) {
    int minc = 1e9; int maxc = 0;

    while (depth[a] != depth[p]) {
        int i = 0;
        for (i; (1 << i) <= depth[a] - depth[p]; i++);
        //cout << "mincost["<< i-1 << "][" << a << "]: " << mincost[i-1][a] << "\n";
        minc = min(minc, mincost[i-1][a]);
        maxc = max(maxc, maxcost[i-1][a]);
        a = parent[i-1][a];
    }

    while (depth[b] != depth[p]) {
        int i = 0;
        for (i; (1 << i) <= depth[b]-depth[p]; i++);
        //cout << "maxcost["<< i-1 << "][" << b << "]: " << maxcost[i-1][b] << "\n";
        minc = min(minc, mincost[i-1][b]);
        maxc = max(maxc, maxcost[i-1][b]);
        b = parent[i-1][b];
    }

    return pii(minc, maxc);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i=1; i<=n-1; i++) {
		cin >> a >> b >> c; 
		adjList[a].push_back(pii(b, c));
		adjList[b].push_back(pii(a, c));
	}

	dfs(1, 0, 0, 0);

    for (int i=1; i<=17; i++) {
        for (int j=1; j<=n; j++) {
            mincost[i][j] = 1e9;
            maxcost[i][j] = 0;
        }
    }

	for (int i=1; i<=17; i++) {
		for (int j = 1; j <=n; j++) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
            mincost[i][j] = min(mincost[i-1][j], mincost[i-1][parent[i-1][j]]);
            maxcost[i][j] = max(maxcost[i-1][j], maxcost[i-1][parent[i-1][j]]);
		}
	}

	cin >> k;
	for (int i=1; i<=k; i++) {
		cin >> a >>b;
	    int p = lca(a, b);
        pii result = minmax(a, b, p);
		cout << result.first << " " << result.second << "\n";
	}

	return 0;
}