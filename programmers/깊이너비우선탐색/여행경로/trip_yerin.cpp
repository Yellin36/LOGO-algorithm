#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk[10005];
vector<string> answer;

bool dfs(string start, vector<vector<string>> tic, vector<string> tmp) {
    tmp.push_back(start);
    
    if(tmp.size() == tic.size()+1) {
        if(answer.empty()) {
            answer = tmp;  
            return true;
        }
    }
    for(int i = 0; i < tic.size(); i++) {
        if(!chk[i] && start == tic[i][0]) {
            chk[i] = true;
            if(dfs(tic[i][1], tic, tmp)) return true;
            chk[i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, {});
    return answer;
}
