#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cost[17][17];
int d[65600][17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j]; //i -> j 비용
        }
    }

    for (int i = 0; i <= (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = 1e9;
        }
    } //d배열 초기화

    d[1][1] = 0;

    for (int i = 2; i < (1 << n); i++) { // 2 ~ 2^n까지 탐색
        for (int j = 1; j <= n; j++) {
            if (i & (1 << (j - 1))) { //j번 노드를 방문 했는지 확인
                int v = i - (1 << (j - 1));
                for (int k = 1; k <= n; k++) {
                    if (cost[k][j] != 0) d[i][j] = min(d[i][j], d[v][k] + cost[k][j]);
                }
            }
        }
    }

    int result = 1e9;
    int last = (1 << n) - 1;

    for (int i = 2; i <= n; i++) {
        if (cost[i][1] != 0) result = min(result, d[last][i] + cost[i][1]);
    }

    cout << result;

    return 0;
}
