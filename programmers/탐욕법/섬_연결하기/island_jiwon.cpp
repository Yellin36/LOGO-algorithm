#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, total_connect = 1;
    
    int connect[n];  //연결된 섬
    for(int i=0;i<n;i++){  //자기자신과 연결
        connect[i] = i;
    }
    
    sort(costs.begin(), costs.end(),compare);  //오름차순, 짧은 경로 순
    
    for(int i=0;i<costs.size();i++){
        if(costs[i][2] == 0 || connect[costs[i][0]] == connect[costs[i][1]])  //0번섬과 연결, 이미 연결된 경우
                continue;
               
        //연결할 다리 탐색
        int next = connect[costs[i][1]];
        for(int j=0;j<n;j++){
            if(connect[j] == next){
                connect[j] = connect[costs[i][0]];
            }
        }
        
        answer += costs[i][2];
        total_connect++;
        
        //모든 섬을 다 연결하였으면 탈출
        if(total_connect == n)
            break;
    }
    return answer;
}
