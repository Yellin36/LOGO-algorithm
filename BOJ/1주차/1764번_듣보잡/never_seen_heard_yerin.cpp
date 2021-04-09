#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string name;

	cin >> N >> M;
	vector<string> heard(N), answer;
	for (int i = 0; i < N; i++) cin >> heard[i]; sort(heard.begin(), heard.end());
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (binary_search(heard.begin(), heard.end(), name)) answer.push_back(name);
		//bool binary_search(시작, 끝, 비교할 문자열) : 이미 정렬된 데이터만 파라미터에 집어넣을 수 있음
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (string i : answer) cout << i << endl;
}
