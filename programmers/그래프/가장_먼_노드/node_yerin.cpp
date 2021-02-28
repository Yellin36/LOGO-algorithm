#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<bool>> g(n+1, vector<bool>(n+1, false));
    vector<bool> chk(n+1,true);
    vector<int> cnt(n+1, 0);
    queue<int> q;
    int max = 0, answer = 0;
    
    for(int i = 0; i < edge.size(); i++) {
        g[edge[i][0]][edge[i][1]] = g[edge[i][1]][edge[i][0]] = true;
    }
    q.push(1); chk[1] = false; chk[1]=1;
    while(!q.empty()) {
        for(int i = 1; i <= n; i++) {
            if(chk[i] && g[q.front()][i]) {
                g[q.front()][i] = g[i][q.front()] = chk[i]= false;
                q.push(i);
                max = cnt[i] = cnt[q.front()] + 1;
            }
        }
        q.pop();
    }
    for(int i=1; i<=n; i++)
        if(max == cnt[i]) answer++;
    return answer;
}
