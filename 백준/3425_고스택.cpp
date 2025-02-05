#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long stack[1001];
int top = 0;

bool stack_method(string cmd, int num) {
    long long result;
    long long first = stack[top - 1];
    
    if (cmd == "NUM") {
        stack[top] = num;
        top++;
    } else if (cmd == "POP") {
        if (top < 1) return false;
        top--;
    } else if (cmd == "INV") {
        if (top < 1) return false;
        stack[top-1] = -stack[top-1];
    } else if (cmd == "DUP"){
        if (top < 1) return false;
        stack[top] = stack[top-1];
        top++;
    } else if (cmd == "SWP"){
        if (top < 2) return false;
        long long second = stack[top - 2];
        stack[top - 1] = second;
        stack[top - 2] = first;
        
    } else { //두 개의 피연산자가 필요한 경우
        if (top < 2) return false;
        long long second = stack[top - 2];
        
        if (cmd == "ADD") result = first + second;
        else if (cmd == "SUB") result = second - first;
        else if (cmd == "MUL") result = first * second;
        else if (cmd == "DIV") {
            if (first == 0) return false;
            result = first * second < 0 ? -(abs(second) / abs(first)): abs(second) / abs(first);
        } else if (cmd == "MOD") {
            if (first == 0 ) return false;
            result = second < 0 ? - (abs(second) % abs(first)) : abs(second) % abs(first);
        } else return false;
        
        if (abs(result) > pow(10, 9)) return false;
        else {
            stack[top - 2] = result;
            top--;
        }
        
    }
    
    return true;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num, itnum, value;
    string cmd;
    vector<string> cmds;
    vector<int> nums;

    while (true) {
        cin >> cmd;
        if (cmd == "QUIT") break;

        //명령어 입력
        while (true) {
            if (cmd == "END") break;
            
            cmds.push_back(cmd);
            if (cmd == "NUM") {
                cin >> num;                //명령어가 NUM인 경우 정수 추가 입력
                nums.push_back(num);
            } else nums.push_back(-1);
            cin >> cmd;
        }
        //cout << "명령어 입력 종료\n";
        cin >> itnum; //반복횟수
        
        bool result = true;
        
        for (int i = 0; i < itnum; i++) {
            cin >> value;
            stack[top] = value;
            top++;
            for (int j = 0; j < cmds.size(); j++) {
                result = stack_method(cmds[j], nums[j]);
                if (!result) break;
            }
            
            if (top != 1 || !result) cout << "ERROR\n";
            else cout << stack[0] << "\n";
            top = 0;
        }
        
        cout << "\n";
        
        cmds.clear();
        nums.clear();
    }

    return 0;
}

