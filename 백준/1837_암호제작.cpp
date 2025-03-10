#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
string n;
int arr[1000001];
vector<int> primes;

// n = p * q -> p,q 중 k 미만의 수가 있으면 BAD
// k 보다 작은 소수 중 n을 나눌 수 있는 수 가 있으면 BAD

bool bigmod(string n, int p) {
    int end = 0;
    int dividend = 0;
    
    while (end < n.length()) {
        dividend = (dividend * 10 + n[end++] - '0') % p;
    }

    if (dividend == 0) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (long long i = 2; i < k; i++) {
        if (arr[i] == 0) {
            primes.push_back(i); //소수
            for (long long j = i * i; j < k; j += i) {
                if (arr[j] == 0) arr[j] = 1;
            } //해당 소수에 대한 배수 지우기
        }
    }

    for (int i = 0; i< primes.size(); i++) {
        if (bigmod(n, primes[i])) {
            cout << "BAD " << primes[i];
            return 0;
        }
    }

    cout << "GOOD";
    return 0;
}
