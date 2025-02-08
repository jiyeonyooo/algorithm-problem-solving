#include <stdio.h>
#include <iostream>

using namespace std;

//큰 경우의 수 -> 파스칼의 삼각형

int pascal[1001][1001];

int com(int n, int k) {
    if (pascal[n][k] != 0) return pascal[n][k];
    else {
        int result = (com(n - 1, k) + com(n - 1, k - 1)) % 10007;
        pascal[n][k] = result;
        return result;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, result;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }

    result = com(n, k);
    
    cout << result;

    return 0;
}
