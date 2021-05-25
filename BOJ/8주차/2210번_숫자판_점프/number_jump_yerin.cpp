#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int y[4] = {1,-1,0,0}, x[4] = {0,0,1,-1};
char board[5][5]={0};
map<string, int> answer;
 
void dfs(int col, int row, int cnt, string num){
    if(cnt == 5){
        answer[num]++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = col + y[i];
        int nx = row + x[i];
        
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
        
        dfs(ny, nx, cnt + 1, num + board[ny][nx]);
    }
}
int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            dfs(i, j, 0, to_string(board[i][j]));

    cout << answer.size() << endl;
}
