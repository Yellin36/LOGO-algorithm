#include <iostream>

using namespace std;


int N, c, r, cnt = 0;

void find(int x, int y, int n) {
    if(x == r && y == c) {
        cout << cnt;
        return;
    }
    if(r < x + n && r >= x &&c < y + n && c >=y) {
        find(x, y, n/2);
        find(x, y+n/2, n/2);
        find(x+n/2, y, n/2);
        find(x+n/2, y+n/2, n);
    }
    else cnt += n*n;
}
int main() {
    scanf("%d %d %d", &N, &r, &c);
    find(0, 0, (1<<N));
}
