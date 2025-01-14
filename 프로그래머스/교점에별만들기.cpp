//
//  교점에별만들기.cpp
//  programmers
//
//  Created by 유지연 on 1/12/25.
//


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
} //y값을 기준으로 내림차순 정렬, y값이 같은 경우 x값 기준 오름차순 정렬

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> meet;
    vector<int> x_point;
    vector<int> y_point;
    int line_num = line.size();
    
    for (int i = 0; i < line_num-1; i++) {
        for (int j = i+1; j < line_num; j++) {
            long long denum = long(line[i][0])*long(line[j][1]) - long(line[i][1])*long(line[j][0]); //ad-bc 분모
            long long x_num = long(line[i][1])*long(line[j][2]) - long(line[i][2])*long(line[j][1]); //bf-ed x 좌표 분자
            long long y_num = long(line[i][2])*long(line[j][0]) - long(line[i][0])*long(line[j][2]); //ec-af y 좌표 분자
            
            if (denum != 0) {
                
                if (x_num % denum == 0 and y_num % denum ==0) {
                    x_point.push_back(int(x_num / denum));
                    y_point.push_back(int(y_num / denum));
                    meet.push_back(make_pair(int(x_num / denum), int(y_num / denum)));
                }
            }
        }
    }
    
    sort(x_point.begin(), x_point.end());
    int min_x = x_point[0];
    int max_x = x_point[x_point.size()-1];
    int x_axis = max_x - min_x + 1;
    
    sort(meet.begin(), meet.end(), cmp);
    int max_y = meet[0].second;
    int min_y = meet[meet.size()-1].second;
    int y_axis = max_y - min_y + 1;
    
    char xy[y_axis][x_axis];
    
    for (int i=0; i<y_axis; i++) {
        for (int j=0; j<x_axis; j++) {
            xy[i][j] = '.';
        }
    }
    
    //(min_x, max_y) -> (0,0)
    //(min_x, max_y -1) -> (1,0)
    //(min_x + 4, max_y) -> (0, 4)
    
    for (int i=0; i<meet.size(); i++) {
        int x_temp = meet[i].first;
        int y_temp = meet[i].second;
        xy[max_y - y_temp][x_temp - min_x] = '*';
    }
    
    for (int i=0; i<y_axis; i++) {
        string result;
        for (int j=0; j<x_axis; j++) {
            result += xy[i][j];
        }
        answer.push_back(result);
    }
    
    return answer;
}
