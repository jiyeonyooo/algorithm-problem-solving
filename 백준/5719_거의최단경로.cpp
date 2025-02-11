#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, from, to;
int u, v, p; //u->v 비용 p (음수 간선 없음)

typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int adj[501][501];
priority_queue<pii, vector<pii>, cmp> update;
vector<int> parent[501];

bool visited[501];
int dist[501];

void del(int from, int to) {
    if (to == from) return;

    for (int j = 0; j < parent[to].size(); j++) {
        //parent[to][j] -> to로 가는 간선 삭제
        if (adj[parent[to][j]][to] == 0) continue; //시간초과 방지!!!!!!!!!!!!!!!!!
        adj[parent[to][j]][to] = 0;
        //cout << parent[to][j] << "-> " << to << "간선 삭제\n";
        del(from, parent[to][j]);
    }
    
}

int dijkstra(int from, int to) {
    
    int cost = -1;

    while (!update.empty()) update.pop();
    update.push({ from, 0 });

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (i == from) dist[i] = 0;
        else dist[i] = 1e9;
    }

    while (!update.empty()) {
        int now = update.top().first;
        cost = update.top().second;

        if (!visited[now]) {

            for (int i = 0; i < n; i++) {

                if (adj[now][i] != 0) {
                    int next = i;
                    int ncost = adj[now][i];

                    if (dist[next] > dist[now] + ncost) {
                        parent[next].clear();
                        parent[next].push_back(now);
                        dist[next] = dist[now] + ncost;
                        update.push({ next, dist[next] });
                    }
                    else if (dist[next] == dist[now] + ncost) {
                        parent[next].push_back(now);
                    }
                }
            }
        }

        visited[now] = true;
        update.pop();
        
        if (now == to) {
            return cost;
        }
    }
    
    cost = -1;
    return cost;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int result;

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) break; //종료조건

        cin >> from >> to;
        
        for (int i=0; i<n; i++) {
            parent[i].clear();
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> p;
            adj[u][v] = p;
        }

        result = dijkstra(from, to);

        del(from, to);
    
        result = dijkstra(from, to);
        cout << result << "\n";
        
    }

    return 0;
}



