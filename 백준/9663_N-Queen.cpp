#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;                //체스판 크기
int cnt = 0;            //result
int visit_y[15] = { 0, };    //세로 방향
int visit_upl[28] = { 0, };    //왼쪽 위 대각선 방향
int visit_upr[28] = { 0, };    //오른쪽 위 대각선 방향

void back(int x) {
    if (x == n + 1) {
        cnt++;
        return;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (visit_y[i] == 0 && visit_upl[x - i + n] == 0 && visit_upr[x + i] == 0) {
                visit_y[i] = 1;
                visit_upl [x - i + n] = 1;
                visit_upr[x + i] = 1;
                back(x + 1);
                visit_y[i] = 0;
                visit_upl[x - i + n] = 0;
                visit_upr[x + i] = 0;
            }
        }
    }
}

int main() {

    cin >> n;
    back(1);
    cout << cnt << "\n"; //결과값 출력
    return 0;
}
