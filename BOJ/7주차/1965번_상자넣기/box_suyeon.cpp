#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, res = 0;
	cin >> n;

	int* box = new int[n];
	int* dp = new int[n];
	memset(dp, 0, n * sizeof(int));

	for (int i = 0; i < n; i++)
		cin >> box[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) {
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
		if (res < dp[i])
			res = dp[i];
	}

	cout << res << '\n';

	delete box;
	delete dp;
}
