#include <iostream>
#include <map>
using namespace std;

int paper[129][129];
int N, xstart, ystart, Wcount = 0, Bcount = 0, white = 0, blue = 0;
int x, y;
int pre, END;

void solution(int x, int y, int N) {
    pre = paper[x][y];
    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (paper[i][j] == 0 && pre == 0)
            {
                pre = 0;
            }
            else if(paper[i][j] == 1 && pre == 1){
                pre = 1;
            }
            else {
                pre = 2;
                break;
            }
        }
        if (pre == 2)
        {
            break;
        }
    }
    if (pre == 0)
    {
        Wcount++;
    }
    else if (pre == 1) {
        Bcount++;
    }
    else {
        solution(x, y, N / 2);
        solution(x, y + N / 2, N / 2);
        solution(x + N / 2, y, N / 2);
        solution(x + N / 2, y + N / 2, N / 2);
    }
    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    //input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> paper[i][j];
        }
    }
    solution(1, 1, N);
    cout << Wcount << "\n" << Bcount << endl;

}
