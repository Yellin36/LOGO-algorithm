#include <iostream>

using namespace std;

int N, x, y;

int solution() {
    int count = 1;
    while (1) {
        if (y % 2 == 0 && y - 1 == x) {
            return count;
        }
        if (x % 2 == 0) {
            x = x / 2;
        }
        else
        {
            x++;
            x = x / 2;
        }
        if (y % 2 == 0) {
            y = y / 2;
        }
        else
        {
            y++;
            y = y / 2;
        }
        count++;
    }
    return -1;
}

int main()
{
    cin >> N >> x >> y;
    if (y < x) {
        int temp = y;
        y = x;
        x = temp;
    }
    cout << solution();
    return 0;
}