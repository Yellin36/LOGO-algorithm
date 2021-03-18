#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
#include <cstring>

using namespace std;

int maze[100][100];
int N, M;  //세로, 가로
int wall[100][100]={{0,},};

void BFS(int x, int y){
    int dx[4] = {0,0,1,-1}; //상하좌우
    int dy[4] = {1,-1,0,0};
    
    for(int i=0;i<4;i++){
        if(x+dx[i] < 0 || x+dx[i] >= N || y+dy[i] < 0 || y+dy[i] >= M){
            continue;
        }
        wall[x+dx[i]][y+dy[i]] = min(wall[x][y] + maze[x+dx[i]][y+dy[i]], wall[x+dx[i]][y+dy[i]]);
    }
}

void Find(int x, int y){
    int dx[4] = {0,0,1,-1}; //상하좌우
    int dy[4] = {1,-1,0,0};
    
    if((x==0 && y==0) || (x==M-1 && y==N-1)){
        return;
    }
    
    for(int i=0;i<4;i++){
        if(x+dx[i] <= 0 || x+dx[i] > N || y+dy[i] <= 0 || y+dy[i] > M){
            continue;
        }
        wall[x][y] = min(wall[x][y],wall[x+dx[i]][y+dy[i]]+maze[x][y]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<wall[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    cin>>M>>N;
    char tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            maze[i][j] = tmp - '0';
            wall[i][j] = 999;
        }
    }
    wall[0][0] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            BFS(i,j);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<wall[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            Find(i,j);
        }
    }
    cout<<wall[N-1][M-1]<<endl;
}

