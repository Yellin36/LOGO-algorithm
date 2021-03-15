#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; //(row, col) : 상 하 좌 우

void chk_field(int row, int col, vector<vector<bool>>& field) {
    field[row][col] = false;

    for (int i = 0; i < 4; i++) {
        if (field[row + dir[i][0]][col + dir[i][1]])
            chk_field(row + dir[i][0], col + dir[i][1], field);
    }
    return;
 }

int main() {
    int T, N, M, K, x, y;

    scanf("%d", &T);                    //테스트 케이스
    while (T--) {
        scanf("%d %d %d", &M, &N, &K);  //가로, 세로, 배추의 위치

        int worm = 0;
        vector<vector<bool>> field(N + 5, vector<bool>(M + 5, false));
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &x, &y);     //K개의 위치
            field[y + 1][x + 1] = true;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (field[i][j]) {
                    chk_field(i, j, field);
                    worm++;
                }
            }
        }
        printf("%d\n", worm);
    }
}
