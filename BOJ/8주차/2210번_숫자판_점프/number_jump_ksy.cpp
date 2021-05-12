#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int number[5][5];
bool visited[1000000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int answer = 0;

void solution(int x, int y, int num, int count) {
    if (count == 5)
    {
        if (!visited[num])
        {
            visited[num] = true;
            answer++;
        }
        return;
    }
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            {
                solution(nx, ny, (num * 10) + number[nx][ny], count + 1);
            }
        }

}

void result() {
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            solution(i, j, number[i][j], 0);
        }
    }
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> number[i][j];
        }
    }
    result();
    
}
