#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> maze;
vector<vector<int>> path;
queue<vector<int>> loc;
int N, M, dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
    cin >> M >> N;
    maze.resize(N + 2);
    path.resize(N + 2);
    maze[0].resize(M + 2, -999);
    for (int i = 1; i <= N; i++) {
        maze[i].resize(M + 2, -999);
        path[i].resize(M + 2, 999999999);
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    } maze[N + 1].resize(M + 2, -999);

    path[1][1] = 0;
    loc.push({ 1, 1 });
    while (!loc.empty()) {
        int col = loc.front()[0], row = loc.front()[1];
        loc.pop();
        for (int i = 0; i < 4; i++) {
            int next_col = col + dir[i][0], next_row = row + dir[i][1];
            if (maze[next_col][next_row] == -999) continue; //범위 밖
            if (maze[next_col][next_row] == 0 && path[next_col][next_row] > path[col][row]) {
                path[next_col][next_row] = path[col][row];
                loc.push({ next_col, next_row });
            }
            else if (maze[next_col][next_row] == 1 && path[next_col][next_row] > path[col][row] + 1) {
                path[next_col][next_row] = path[col][row] + 1;
                loc.push({ next_col, next_row });
            }
        }
    }
    printf("%d", path[N][M]);
}
