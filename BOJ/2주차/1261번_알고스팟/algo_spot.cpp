#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
#define INF 987654321
using namespace std;

int n,m;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool is_possible(int row,int col){
    if(row<0 || row>=n || col<0 || col>=m) return false;
    return true;
}

void bfs(){
    queue<pair<int, int>> q;
    queue<pair<int, int>> next_q;
    
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(is_possible(nx, ny)){
                if(dist[nx][ny] == -1){
                    if(map[nx][ny] == 0){
                        dist[nx][ny] = dist[x][y];
                        q.push(make_pair(nx, ny));
                    }else{
                        dist[nx][ny] = dist[x][y] + 1;
                        next_q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        
        if(q.empty()){
            swap(q, next_q);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
            dist[i][j] = -1;
        }
    }
    
    bfs();
    cout << dist[n-1][m-1] << endl;
    
    return 0;
}

//혼자 풀지 못한 문제
