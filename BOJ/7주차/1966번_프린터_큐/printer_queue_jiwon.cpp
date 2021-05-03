#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int cnt = 0, tmp;
		for (int i = 0; i < a; i++) {
			cin >> tmp;
			q.push( { i, tmp });
			pq.push(tmp);
		}
		while (!q.empty()) {
			int s = q.front().second;
			int f = q.front().first;
			q.pop();  //와,,씨 이걸안해서..
			if (pq.top() == s) {
				pq.pop();
				cnt++;
				if (f == b) {
					cout << cnt << endl;
					break;
				}
			} else
				q.push( { f,s });

		}

	}
}

