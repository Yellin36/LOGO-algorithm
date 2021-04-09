#include <string>
#include <vector>

using namespace std;

vector<bool> chk(205, true);

void dfs(int target, vector<vector<int>>& c) {
    if(!c[target][target]) return;
    
    c[target][target] = 0;
    for(int i = 0; i < c[target].size(); i++) {
        if(c[target][i]) {
            dfs(i, c);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        if(computers[i][i]) {
            dfs(i, computers);
            answer++;            
        }   
    }
    return answer;
}
