#include <stdio.h>
#include <iostream>

using namespace std;

int n, m, k;
bool visited[21] = {false, };
int num[21];

bool used[21] = {false, };
int input[21];
int cnt = 0;

void permutation(int order, int p) {
    if (order == p) {
        cnt++;
        if (m == 1 && cnt == k ) for (int i=0; i<p; i++) cout << num[i] << " ";
        return;
    }
    
    for (int i=1; i<=p; i++) {
        if (!visited[i]) {
            visited[i] = true;
            num[order] = i;
            permutation(order + 1, p);
            visited[i] = false;
         }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m; //1부터 n까지의 자연수
    
    if (m == 1) { //k번째 순열 구하기
        cin >> k;
        permutation(0, n);
    } else if (m == 2) { //입력받은 순열의 순서 구하기
        for (int i=1; i<=n; i++) {
            cin >> k;
            input[i] = k;
        }
        
        int result = 1;
        int a = 0;
        permutation(0, n-1); // (n-1)!
        
        for (int i=1; i<=n;i++){
            used[input[i]] = true;
            for (int j=1; j<input[i]; j++) {
                if (used[j] == false) a++;
            }
            result += cnt * a;
            cnt = i != n ? cnt / (n-i) : 0;
            a = 0;
        }
        cout << result;
    }
    
    return 0;
}

