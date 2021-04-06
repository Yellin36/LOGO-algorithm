#include <iostream>
#include <cmath>
using namespace std;
int cnt = 0, N, r, c;

void Z(int row, int col, int n) {
	int range = int(pow(2, n));
	if (row == r && col == c) {
		cout << cnt << endl;
		return;
	}

	if (r < row + range && r >= row && c < col + range && c >= col) {
		Z(row, col, n - 1);
		Z(row, col + range / 2, n - 1);
		Z(row + range / 2, col, n - 1);
		Z(row + range / 2, col + range / 2, n - 1);
	}
	else 
		cnt += range * range;
}

int main()
{
	cin >> N >> r >> c;

	Z(0, 0, N);
}
