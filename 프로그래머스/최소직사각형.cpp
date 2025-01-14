//
//  최소직사각형.cpp
//  programmers
//
//  Created by 유지연 on 1/14/25.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        w = max(w, min(sizes[i][0], sizes[i][1]));
        h = max(h, max(sizes[i][0], sizes[i][1]));
    }
    
    answer = w*h;
    return answer;
}
