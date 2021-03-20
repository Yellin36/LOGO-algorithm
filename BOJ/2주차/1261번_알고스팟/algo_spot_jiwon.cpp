#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int maze[100][100];
int N, M;  //세로, 가로
int wall[100][100]={{0,},};
bool visited[100][100];

void DFS(int x, int y,int walls){
    if(wall[x][y] <= walls)
        return;
    wall[x][y] = walls;
    
    if(x == M-1 && y == N-1)
        return;
    
    
    int dx[4] = {0,0,1,-1}; //상하좌우
    int dy[4] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int new_x = x + dx[i], new_y = y + dy[i];
        if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M || visited[new_x][new_y]){
            continue;
        }
        visited[new_x][new_y] = true;
        DFS(new_x,new_y,walls+maze[new_x][new_y]);
        visited[new_x][new_y] = false;
    }
}


int main(){

    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&maze[i][j]);
            wall[i][j] = 999;
        }
    }
    
    visited[0][0] = true;
    DFS(0,0,0);
    
    cout<<wall[N-1][M-1]<<endl;
}

