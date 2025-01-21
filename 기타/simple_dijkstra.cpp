//
//  simple_dijkstra.cpp
//  algorithm
//
//  Created by 유지연 on 1/21/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

//방문하지 않은 노드 중 현재의 최단 거리가 가장 짧은 노드의 번호 리턴
int smallest_node (int node, vector<int> &distance, vector<bool> &visited) {
    unsigned long result = visited.size();
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == false) result = distance[i] < result ? i : result;
        //std::cout << "result: " << result << "\n";
    }
    return int(result);
}

void update_distance(int node, vector<vector<int>> &graph, vector<int> &distance, vector<bool> &visited) {
    for (int i=1; i<distance.size(); i++) {
        if (visited[i] == false && graph[node][i] != INF) {
            distance[i] = distance[node] + graph[node][i] < distance[i] ? distance[node] + graph[node][i] : distance[i];
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int vertex, edge;   //vertex, edge의 개수를 담는 변수
    int start_node;     //시작 node의 위치
    
    std::cin >> vertex >> edge >> start_node;
    std::vector<std::vector<int>> graph(vertex+1, std::vector<int>(vertex+1, INF));
    std::vector<bool> visited(vertex+1, false);     //각 노드에 대한 방문 여부
    std::vector<int> distance(vertex+1, INF);       //각 노드에 대한 현재의 최단거리
    distance[start_node] = 0;
    //graph의 노드들 간의 정보를 저장하는 2차원 vector
    //std::cout << graph.size();
    
    //(u, v, w): u -> v 로 가는 weight w의 edge가 존재
    for (int i=0; i<edge; i++) {
        int lnode, rnode, weight;
        std::cin >> lnode >> rnode >> weight;
        if (graph[lnode][rnode] != INF) graph[lnode][rnode] = graph[lnode][rnode] < weight ? graph[lnode][rnode] : weight;
        else graph[lnode][rnode] = weight;
        //graph[rnode][lnode] = weight;
    }
    
    int temp = start_node;
    visited[temp] = true;
    
    while (true) {
        update_distance(temp, graph, distance, visited);
//        for (int i=1; i<distance.size(); i++) {
//            std::cout << distance[i] << "  ";
//        }
        temp = smallest_node(temp, distance, visited);
        if (temp == vertex+1) break;
        //std::cout << "temp: " << temp << "\n";
        visited[temp] = true;
    }
    
    //std::cout << "RESULT\n";
    for (int i=1; i<distance.size(); i++) {
        if (distance[i] == INF) std::cout << "INF" << "\n";
        else std::cout << distance[i] << "\n";
    }
    
    return 0;
}

