#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, l, c = 0, answer = 0, s, e;
	vector<pair<int, int>> arr;
	
	cin >> n >> l;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		arr[i] = { s, e };
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (c < arr[i].second) {
			c = arr[i].first > c ? arr[i].first : c;
			int t = (arr[i].second - c - 1) / l + 1;
			answer += t;
			c += t * l;
		}
	}
	cout << answer;
}
