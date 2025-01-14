//
//  divideNetwork.cpp
//  programmers
//
//  Created by 유지연 on 1/14/25.
//
// 프로그래머스 > 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971#qna

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited(101, 0);

void dfs(vector<vector<int>> &network, int node, int &count) {
    count++;
    visited[node] = 1; //현재 노드 방문 처리
    for (int i = 0; i < network[node].size(); i++) {
        if (visited[network[node][i]] == 1) continue; //이미 방문된 노드인 경우
        else dfs(network, network[node][i], count);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n; //노드 개수 차이는 전체 노드 개수 n 보다 커질 수 없음
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> network(n+1, vector<int>());
        std::fill(visited.begin(), visited.end(), 0);
        int n1 = wires[i][0];
        int n2 = wires[i][1];
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue; //끊을 edge이므로 network에 추가 X
            network[wires[j][0]].push_back(wires[j][1]);
            network[wires[j][1]].push_back(wires[j][0]);
        }
        int count = 0;
        dfs(network, n1, count);
        if (abs(count - abs(n - count)) < answer) {
            answer = abs(count - abs(n - count));
        }
    }

    return answer;
}
