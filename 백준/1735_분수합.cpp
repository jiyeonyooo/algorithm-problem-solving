#include <stdio.h>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int a, b, c, d; //a/b + c/d
    cin >> a >> b >> c >> d;
    int num = a * d + c * b;
    int denum = b * d;

    int di = gcd(num, denum);

    cout << num / di << " " << denum / di;

}
