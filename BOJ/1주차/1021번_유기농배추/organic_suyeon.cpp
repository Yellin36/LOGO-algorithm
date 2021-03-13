#include <iostream>
using namespace std;

int map[51][51];
int visited[51][51];
int t, m, n, k;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x);

int main()
{
	cin >> t;
	int x, y, sum;
	
	while (t) {
		sum = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					sum++;
					dfs(i, j);
				}
			}
		}

		t--;
		cout << sum << endl;
	}
	return 0;
}

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;

		if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
			dfs(ny, nx);
		}
	}
}
