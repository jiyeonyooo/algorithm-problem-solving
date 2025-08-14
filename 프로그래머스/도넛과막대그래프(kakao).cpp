#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    map<int, vector<int>> inout;
    int edgeNum = edges.size();     //간선의 개수
    int vertex;                     //생성된 정점
    int graphNum;                   //전체 그래프의 개수
    
    for (int i = 0; i < edgeNum; i++) {
        //edges[i][0] -> edges[i][1] 간선 존재
        int from = edges[i][0];
        int to = edges[i][1];
        if (inout.find(from) != inout.end()) inout[from][1]++;
        else inout[from] = {0, 1};
        if (inout.find(to) != inout.end()) inout[to][0]++;
        else inout[to] = {1, 0};
    }
    
    for (auto v: inout) {
        if(v.second[0] == 0 && v.second[1] >=2) {
            vertex = v.first;
            graphNum = v.second[1];
            break;
        }
    }
    
    for (int i = 0; i < edgeNum; i++) {
        if (edges[i][0] == vertex) inout[edges[i][1]][0]--;
    }
    
    int donut = 0;
    int stick = 0;
    int eight = 0;
    
    for (auto v: inout) {
        if (v.second[0] == 0 && v.first != vertex) stick++;
        if (v.second[0] == 2 && v.second[1] == 2) eight++;
    }
    donut = graphNum - stick - eight;
    
    answer = {vertex, donut, stick, eight};
    
    return answer;
}
