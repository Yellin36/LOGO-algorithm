#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> com;
bool visit[101];
int line;
int cnt = 0;
void find(int);

int main() {
	int comcnt, start, end;
	scanf("%d %d", &comcnt, &line);
	com.resize(comcnt + 1);
	for (int i = 0; i < line; i++) {
		scanf("%d %d", &start, &end);
		com[start].push_back(end);
		com[end].push_back(start);
	}
	find(1);

	printf("%d", cnt-1);
	return 0;
}

void find(int n) {
	cnt++;
	visit[n] = true;
	for (int i = 0; i < com[n].size(); i++) {
		if (!visit[com[n][i]])
			find(com[n][i]);
	}
	return;
}
