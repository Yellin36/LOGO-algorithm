#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int board[5][5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
set<int> answer;

void dfs(int depth, int x, int y, int cur){
    if(depth == 5){
        answer.insert(cur);
        return;
    }
    
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        
        dfs(depth+1, nx, ny, cur * 10 + board[nx][ny]);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>board[i][j];
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(0,i,j,board[i][j]);
        }
    }
    
    cout<<answer.size();
}

