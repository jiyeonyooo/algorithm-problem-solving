#include <stdio.h>
#include <iostream>

using namespace std;

int p[1001] = { 0, };

int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int result = -1;
    
    for (int i=2; i<= n; i++) {
        if (p[i] == 0) {
            for (int j = i; j<=n; j+= i) {
                if (p[j] == 0) {
                    p[j] = 1;
                    cnt++;
                }
                if (cnt == k) {
                    result = j;
                    break;
                }
            }
            if (result != -1) break;
        }
    }
    
    cout << result;

    return 0;
}
