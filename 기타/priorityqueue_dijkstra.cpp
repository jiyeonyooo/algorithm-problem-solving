//
//  algorithm
//
//  Created by 유지연 on 1/22/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF -100

using namespace std;

void update_distance(int node, vector<vector<pair<int, int>>> &graph, vector<int> &distance, vector<bool> &visited, priority_queue<pair<int, int>> &pq) {
    for (int i=0; i<graph[node].size(); i++) {
        int next_node = graph[node][i].first;
        
        if (visited[next_node] == false) {
            if (distance[node] + graph[node][i].second > distance[next_node]) {
                distance[next_node] = distance[node] + graph[node][i].second;
                pq.emplace(distance[next_node], next_node);
            }
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int vertex, edge;   //vertex, edge의 개수를 담는 변수
    int start_node;     //시작 node의 위치
    
    std::cin >> vertex >> edge >> start_node;
    std::vector<std::vector<pair<int, int>>> graph(vertex+1);
    std::vector<bool> visited(vertex+1, false);     //각 노드에 대한 방문 여부
    std::vector<int> distance(vertex+1, INF);       //각 노드에 대한 현재의 최단거리
    distance[start_node] = 0;
    //graph의 노드들 간의 정보를 저장하는 2차원 vector
    //std::cout << graph.size();
    
    //(u, v, w): u -> v 로 가는 weight w의 edge가 존재
    for (int i=0; i<edge; i++) {
        int lnode, rnode, weight;
        std::cin >> lnode >> rnode >> weight;
        graph[lnode].emplace_back(rnode, -weight);
    }
    
    priority_queue<pair<int, int>> pq; //(거리, 노드)
    
    pq.emplace(0, start_node);
    
    while (!pq.empty()) {
        int current_node = pq.top().second;
        pq.pop();
        if (visited[current_node] == false) { //아직 방문을 안한 노드인 경우
            update_distance(current_node, graph, distance, visited, pq);
            visited[current_node] = true;
        }
    }
    
    //std::cout << "RESULT\n";
    for (int i=1; i<distance.size(); i++) {
        if (distance[i] == INF) std::cout << "INF" << "\n";
        else std::cout << -distance[i] << "\n";
    }
    
    return 0;
}

