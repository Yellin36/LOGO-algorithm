#include <iostream>
using namespace std;

int map[128][128] = { 0, };
int white = 0, blue = 0;

void divide(int x, int y, int size) {
	int flag = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] == 0)
				flag++;
		}
	}

	if (flag == 0) blue++;
	else if (flag == size * size) white++;
	else {
		divide(x, y, size / 2);
		divide(x, y + size / 2, size / 2);
		divide(x + size / 2, y, size / 2);
		divide(x + size / 2, y + size / 2, size / 2);
	}
}

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			map[i][j] = num;
		}
	}

	divide(0, 0, n);

	cout << white << '\n' << blue << '\n';
}
