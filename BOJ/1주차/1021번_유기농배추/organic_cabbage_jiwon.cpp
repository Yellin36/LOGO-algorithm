#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

int M, N, K; //배추밭의 가로,세로길이, 배추가 심어져있는 위치 개수
int cabbage[51][51];
bool check[51][51];

void DFS(int y, int x){
    int dx[4] = {0,0,-1,1}; //상, 하, 좌, 우
    int dy[4] = {-1,1,0,0};
    
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny<0 || ny>=N || nx<0 || nx >= M) //범위 넘으면 안됨
            continue;
        if(cabbage[ny][nx] && !check[ny][nx]){
            check[ny][nx] = true;
            DFS(ny,nx);
        }
    }
}


int main(){
    int T; //테스트 케이스 수
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>M>>N>>K;
        memset(cabbage,0,sizeof(cabbage));
        memset(check,false,sizeof(check));
        
        for(int i=0;i<K;i++){
            int x, y; //X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)
            cin>>x>>y;
            cabbage[y][x] = 1;
        }
        
        int sum = 0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(cabbage[i][j] && !check[i][j]){
                    sum++;
                    check[i][j] = true;
                    DFS(i,j);
                }
            }
        }
        cout<<sum<<endl;
    }
    
}

