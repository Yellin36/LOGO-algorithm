#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, st, ed, sum = 0;		// N은 물웅덩이 개수, L은 물웅덩이를 덮을 수 있는 널빤지의 길이
	cin >> N >> L;
	vector<pair<int, int>> num;		//웅덩이의 시작 위치와 끝 위치 저장

	int tmp = N;
	while (tmp--) {
		cin >> st >> ed;
		num.push_back(make_pair(st, ed));
	}

	sort(num.begin(), num.end());
	
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int first = num[i].first;
		int second = num[i].second;
		if (idx >= second - 1) continue;

		if (idx >= first) first = idx + 1;
		else idx = first - 1;

		int len = second - first;

		int cnt = len / L;
		if (len % L != 0 && len > 0) cnt++;

		for (int j = 0; j < cnt; j++) idx += L;

		sum += cnt;
	}

	cout << sum << endl;
	
}
