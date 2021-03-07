#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    
    for(int i=0; i<results.size();i++){
        int win = results[i][0];
        int lose = results[i][1];
        graph[win-1][lose-1] = true;
    }
    
    //플로이드와샬 알고리즘
    //k 중간에 지나는 노드
    for (int k = 0; k < n; k++) {
        //i 출발노드
        for (int i = 0; i < n; i++) {
            //j 도착 노드
            for (int j = 0; j < n; j++) {
                if (graph[i][k] && graph[k][j]) 
                    graph[i][j] = true;
          }
        }
    }
    
    //순위를 알 수 있는 경우 체크
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) 
                continue;
            if(graph[i][j] || graph[j][i])
                cnt++;
        }
        if (cnt == n-1)
            answer++;
    }
    
    return answer;
}
