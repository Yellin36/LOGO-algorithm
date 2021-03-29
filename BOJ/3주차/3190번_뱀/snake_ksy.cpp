#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int n, k, x, y, l;
int sec = 0, input = 0;
char indirec;
int where = 0; // 0 right 1 row 2 left 3 high
queue<pair<int, char>> direc;
deque<pair<int, int>> snake;
vector<vector<int>> map(101, vector<int>(101, 0));

bool can_move(int x, int y) { // x 세로, y 가로
    if (x < 0 || x >= n || y < 0 || y >= n) {
        sec++;
        return 0;
    }
    else if (map[x][y] >= 0) {
        return 1;
    }
    if (map[x][y] == -1) {
        sec++;
        return 0;
    }
}

void lego() {
    switch (where)
    {
    case 0: y++; break;
    case 1: x++; break;
    case 2: y--; break;
    case 3: x--; break;
    }
}

void direction() {
    switch (direc.front().second) {
        case 'D': // 오른쪽
            where++;
            break;
        case 'L': // 왼쪽
            if (where == 0) where = 4;
            where--;
            break;
    }
    direc.pop();
    if(direc.size() == 0) direc.push(make_pair(0, 0));
    if (where == 4) where = 0;
    lego();
}

int main() {
    snake.push_back(make_pair(0, 0));
    cin >> n >> k;

    for (int i = 0; i < k; i++) { // 사과 넣기
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++) { // 뱀 방향전환
        cin >> x >> indirec;
        direc.push(make_pair(x, indirec));
    }
    x = 0, y = 1;
    while (can_move(x, y)) {
        sec++;
        if (map[x][y] == 1) { // 사과
            map[x][y] = -1;
            snake.push_back(make_pair(x, y));
        }
        else {
            map[x][y] = -1;
            snake.push_back(make_pair(x, y));
            map[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        if (sec == direc.front().first) {
            direction();
        }
        else {
            lego();
        }
    }
    cout << sec;
}
