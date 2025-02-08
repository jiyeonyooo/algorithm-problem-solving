#include <stdio.h>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

string input[11];
bool visited[11] = {false, };
set<string> p;

int n, k;
int cnt = 0;

void permutation(int length, string num) {
    
    if (length == k) {
        if (p.find(num) == p.end()) cnt++; //기존에 만들어지지 않은 정수인 경우
        //cout << num << "생성\n";
        p.insert(num);
        return;
    }
    
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            visited[i] = true;      //방문 처리
            permutation(length+1, num + input[i]);
            visited[i] = false;     //방문 처리 해제
        }
    }
    
    return;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(NULL);
    
    string m;
    cin >> n >>  k;
    
    for (int i=1; i<=n; i++) {
        cin >> m;
        input[i] = m;
    }
    
    permutation(0, "");
    cout << cnt;
    
    return 0;
}


