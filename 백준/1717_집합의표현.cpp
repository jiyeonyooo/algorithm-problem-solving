#include <stdio.h>
#include <iostream>

using namespace std;

int parent[1000001];
int n, m, num, a, b;

//a의 대표번호 return
int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void unions(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    parent[parent_b] = parent_a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    //각 노드의 대표번호를 자기 자신으로 초기화
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> num >> a >> b;
        if (num == 0) {        //union 연산
            unions(a, b);
        }
        else if (num == 1) {    //find 연산
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
