#include <iostream>
#define min(a, b) (a > b) ? b : a

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, answer = 987654321;
	int d[1005][3];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
		if (!i) continue;

		d[i][0] += min(d[i - 1][1], d[i - 1][2]);
		d[i][1] += min(d[i - 1][0], d[i - 1][2]);
		d[i][2] += min(d[i - 1][0], d[i - 1][1]);
	}
	for (int i = 0; i < 3; i++) {
		if (answer > d[n - 1][i]) answer = d[n - 1][i];
	}
	cout << answer;
}
