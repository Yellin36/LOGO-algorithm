#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, l, map[105][105];
queue<pair<int, char>> dir;
//*****************************************
//벽 또는 자기자신의 몸과 부딪히면 게임오버
//사과를 먹으면 몸 길이 증가
//*****************************************
int main() {
	scanf("%d", &n);		//맵 생성(n * n의 정사각형)
	scanf("%d", &k);		//사과 위치('A')
	for (int i = 0; i < k; i++) {
		int col, row;
		scanf("%d %d", &col, &row);
		map[col][row] = 'A';	
	}
	scanf("%d", &l);		//방향정보: dir = { 시간, 방향 } D : 오른쪽/ L : 왼쪽
	for (int i = 0; i < l; i++) {
		int sec; char d;
		scanf("%d %c", &sec, &d);
		dir.push({ sec, d });
	}dir.push({ 10005, 'D' });

	int way[2] = { 0, 1 };		//앞으로 갈 방향
	int x, y, nx, ny, time = 0;	//현재위치: (y, x) -> 옮길위치(ny, nx), 현재시간: time

	deque<pair<int, int>> s;	//뱀
	s.push_back({ 1, 1 });		//시작위치: (1, 1)
	
	while (!dir.empty()) {
		pair<int, char> d = dir.front();

		for (int i = time; i < d.first; i++) {
			x = s.front().second, y = s.front().first;
			nx = x + way[1], ny = y + way[0];

			map[y][x] = 'x';		//뱀이 있는 곳
			
			if (nx < 1 || nx > n || ny < 1 || ny > n || map[ny][nx] == 'x') {	//벽에 닿았거나 자신의 몸에 닿았을 때
				printf("%d", time + 1);
				return 0;
			}
			s.push_front({ ny, nx });	//(ny, nx)로 옮길 수 있으므로 이동
			
			if (map[ny][nx] != 'A') {	//옮긴 위치에 사과가 없는 경우 -> 뱀의 맨 뒷부분을 지워줌(뱀의 길이 유지)
				map[s.back().first][s.back().second] = ' ';
				s.pop_back();
			}
			time++;				//1초 증가
		}
		int tmp = way[0];			//방향전환
		if (way[0] == 0) {
			if (d.second == 'D')	{ way[0] = way[1];		way[1] = tmp; } 
			else			{ way[0] = -1 * way[1]; way[1] = tmp; }
		} 
		else {
			if (d.second == 'D')	{ way[0] = way[1]; way[1] = -1 * tmp; } 
			else			{ way[0] = way[1]; way[1] = tmp; }
		}
		dir.pop();
	}
	printf("%d", time);
}
