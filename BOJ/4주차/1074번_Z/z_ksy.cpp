#include <iostream>

using namespace std;

int N, r, c;
int x, y, ans;

void solve(int x, int y, int n) {

    if (x == r && y == c) { // 탐색값과 결과물 일치시 return
        cout << ans << "\n";
        return;
    }


    if (r < x + n && r >= x && c < y + n && c >= y) // (r, c) 가 사분면에 속할때 수행
    {
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
    }
    // (r,c)가 현재 사분면이 아니면 그냥 사분면의 크기만큼 더해준다 (탐색한걸로 친다)
    else ans += n * n;

}

int main()
{
    ios::sync_with_stdio(false); // 독립적 버퍼사용
    cin.tie(0);

    cin >> N >> r >> c;

    solve(0, 0, (1 << N)); // 비트 값으로 제곱값 계산

    return 0;
}
