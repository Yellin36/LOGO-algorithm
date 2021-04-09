#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> node;

int count(int num){
    bool chk[20001] = {false,};
    queue<int> q;
    q.push(num);
    chk[num] = true;
    int ans=0;
    
    while(!q.empty()){
        int n = (int)q.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            int s = q.front();
            q.pop();
            
            for(int j=0;j<node[s].size();j++){
                if(!chk[node[s][j]]){
                    chk[node[s][j]] = true;
                    q.push(node[s][j]);
                    cnt++;
                }
            }
        }
        if(q.empty())
            break;
        ans = cnt;
    }
    return ans;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    node.resize(n);
    for(int i=0;i<edge.size();i++){
        node[edge[i][0]-1].push_back(edge[i][1]-1);
        node[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    
    answer = count(0);
    return answer;
}
