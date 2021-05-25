#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> road;
int answer = 0;

int solution(int L) {
	int loc = -1;
	for (int i = 0; i < road.size(); i++)
	{
		if (loc < road[i].first) {
			loc = road[i].first;
		}

		while (loc < road[i].second) {
			loc += L;
			answer++;
		}
	}
	return answer;
}
int main() {
	int N, L, x, y;
	cin >> N >> L;

	
	for (int i = 0; i < N; i++)
	{

		cin >> x >> y;
		road.push_back(make_pair(x, y));
	}
	sort(road.begin(), road.end());

	cout << solution(L);
}