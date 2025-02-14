#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int n, m, a, b; //n: 샘플 종류의 개수, m: 한 일의 수
long long w;
int answer;
string cmd;

int p[100001];
long long d[100001];

int find(int a) {
    if (p[a] == a) return a;
    else {
        int pa = find(p[a]);
        d[a] += d[p[a]];
        return p[a] = pa;
    }
}

void uni(int a, int b, long long w) {
    int pa = find(a);
    int pb = find(b);
    
    if (pa != pb) {
        p[pa] = pb;
        d[pa] = d[b] - d[a] - w;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break; //종료조건

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            d[i] = 0;
        } //parent, dist 배열 초기화

        for (int i = 0; i < m; i++) {
            cin >> cmd;
            if (cmd == "!") {
                cin >> a >> b >> w;
                uni(a, b, w);
            }
            else if (cmd == "?") {
                cin >> a >> b;
                int pa = find(a);
                int pb = find (b);
                
                if (pa == pb) cout << d[b] - d[a] << "\n";
                else cout << "UNKNOWN\n";
            }
        }
    }

    return 0;
}

