#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> primes; //min heap

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;        //소수의 개수, n번째 값
    int prime;
    int cnt = 0;

    vector<int> p; //입력 소수 저장 배열

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> prime;
        p.push_back(prime);
        primes.push(prime);
    }

    long long now = 0;

    while (cnt < n) {

        if (now == primes.top()) {
            primes.pop();
        }
        else {
            now = primes.top();
            primes.pop();
            cnt++;

            for (int j = 0; j < k; j++) {
                if (now * p[j] >= 2147483647) continue;
                else primes.push(now * p[j]);
            }
        }
    }

    cout << now;

    return 0;
}
