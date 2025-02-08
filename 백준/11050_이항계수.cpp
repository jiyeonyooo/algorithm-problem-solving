#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    int result = 1;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }

    cout << result;
    return 0;
}
