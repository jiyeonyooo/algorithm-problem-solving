#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int result = 0;
int tri[501][501];
int maxsum[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        maxsum[i][0] = 0;
        maxsum[i][i + 1] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            maxsum[i][j] = tri[i][j] + max(maxsum[i - 1][j - 1], maxsum[i - 1][j]);
            if (i == n && result < maxsum[i][j]) result = maxsum[i][j];
        }
    }

    cout << result;

    return 0;
}
