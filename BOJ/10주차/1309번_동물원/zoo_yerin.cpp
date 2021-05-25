#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, answer = 0;

	scanf("%d", &n);
	vector<vector<int>> cage(n, vector<int>(3, 0));

	cage[0][0] = cage[0][1] = cage[0][2] = 1;
	for (int i = 1; i < n; i++) {
		cage[i][0] = (cage[i - 1][0] + cage[i - 1][1] + cage[i - 1][2]) % 9901;
		cage[i][1] = (cage[i - 1][0] + cage[i - 1][2]) % 9901;
		cage[i][2] = (cage[i - 1][0] + cage[i - 1][1]) % 9901;
	}
	answer = cage[n - 1][0] + cage[n - 1][1] + cage[n - 1][2];
	printf("%d\n", answer % 9901);
}
