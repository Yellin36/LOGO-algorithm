#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, m, s, e;

	scanf("%lld %lld", &n, &m);
	vector<pair<int, int>> boat;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &s, &e);
		if (s > e) boat.push_back({ e, s });
	}
	sort(boat.begin(), boat.end());

	long long distance = boat[0].second - boat[0].first;
	long long cur = boat[0].second;
	for (int i = 1; i < boat.size(); i++) {
		if (boat[i].first <= cur) {
			if (cur < boat[i].second) {
				distance += boat[i].second - cur;
				cur = boat[i].second;
			}
		}
		else {
			distance += boat[i].second - boat[i].first;
			cur = boat[i].second;
		}
	}
	printf("%lld\n", m + 2 * distance);
}
