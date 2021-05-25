#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a;
	int n, top = 9, answer = 0, len = 10000000;

	cin >> n;
	vector<string> words(n);
	vector<pair<int, char>> alpha(26, {-1, 0});

	for (int i = 0; i < n; i++) {
		int l = 1;
		cin >> a;
		reverse(a.begin(), a.end());
		words[i] = a;
		for (int j = 0; j < a.size(); j++) {
			char c = words[i][j] - 'A';
			if (alpha[c].first == -1) {
				alpha[c].first = 0;
				alpha[c].second = words[i][j];
			}
			alpha[c].first += l;
			l *= 10;
		}
	}
	sort(alpha.begin(), alpha.end(), compare);

	for (int i = 0; i < 10; i++) {
		if (alpha[i].first == -1) break;
		answer += alpha[i].first * top--;
	}
	
	cout << answer;
}
