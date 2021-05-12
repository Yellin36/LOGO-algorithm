#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int testcase, n, m;
	vector<pair<int, int>> v;
	cin >> testcase;

	while (testcase--) {
		int j = 0, answer = 1;
		cin >> n >> m;

		int* importance = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> importance[i];
			v.push_back(make_pair(i, importance[i]));
		}

		vector<pair<int, int>> ::iterator it = v.begin();
		while (true) {
			int tmpIdx = v[j].first, tmp = v[j].second, flag = 0;

			for (int i = 1; i < v.size(); i++) {
				if (tmp < v[i].second) {
					it = v.erase(it);
					v.push_back(make_pair(tmpIdx, tmp));
					flag = -1;
					break;
				}
			}
			if (flag == 0) {
				if (m == v[0].first) {
					cout << answer << '\n';
					break;
				}
					it = v.erase(it);
					answer++;
			}
		}
		v.clear();
	}

}
