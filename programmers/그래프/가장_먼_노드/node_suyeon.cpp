#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> grape(n+1);
    vector<int> distance(n+1, 0);
    vector<bool> visit(n+1, false);   


    for(int i = 0 ; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];

        grape[start].push_back(end);
        grape[end].push_back(start);
    }

    queue<int> q;
    q.push(1);
    visit[1] = true;

    while(!q.empty()) {
        int startNode = q.front();
        q.pop();
        
        for(int i = 0; i < grape[startNode].size(); i++) {
            int endNode = grape[startNode][i];
            //cout << endNode << ' ';
            if(!visit[endNode]) {
                visit[endNode] = true;

                distance[endNode] = distance[startNode] + 1;
                q.push(endNode);
            }
        }
    }

    sort(distance.begin(), distance.end(), greater<int>());

    for(int i = 0; i < distance.size(); i++) {
        if(distance[i] == distance[0])
            answer++;
    }


    return answer;
}
