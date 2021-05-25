#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int map[5][5] = { 0, };
vector<int> v;

void dfs(int x, int y, int num, int numLen) {
	if (numLen == 6) {
		v.push_back(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;

		dfs(nx, ny, map[nx][ny] + 10 * num, numLen + 1);
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, map[i][j], 1);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << endl;


}
