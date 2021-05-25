#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> link;		//경로
bool chk[105] = {false};		//방문여부(true: O, false: X)
int answer = -1;				//웜 바이러스에 감염된 컴퓨터의 수

void bfs(int start) {
    chk[start] = true; answer++;
    for(int i=0; i<link[start].size(); i++) {
        if(!chk[link[start][i]]) {
            bfs(link[start][i]);
        }
    }
}
int main() {
    int c, n, x, y;
    scanf("%d%*c%d", &c, &n);

    link.resize(c+1);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        link[x].push_back(y);
        link[y].push_back(x);
    }
    bfs(1);
    printf("%d", answer);
}
