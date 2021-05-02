#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> MAP[101];
bool check[100] = { false, };
int answer = 0;

void virus(int start){
	check[start] = true;
		for (int i = 0; i < MAP[start].size(); i++)
		{
			if (!check[MAP[start][i]]) {
				virus(MAP[start][i]);
				answer++;
			}
		}
	return;
}

int main() {
	int x, y, input, input2;
	cin >> x >> y;

	for (int i = 0; i < y; i++) {
		cin >> input >> input2;
		MAP[input].push_back(input2);
		MAP[input2].push_back(input);
	}

	virus(1);
	cout << answer;
}