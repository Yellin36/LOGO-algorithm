#include <string>
#include <vector>

using namespace std;
bool visit[201];

void find(vector<vector<int>> com, int num){
    visit[num] = true;
    for (int i = 0; i < com[num].size(); i++) {
        if (!visit[i] && com[num][i])
            find(com,i);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            answer++;
            find(computers, i);
        }
    }
    return answer;
}
