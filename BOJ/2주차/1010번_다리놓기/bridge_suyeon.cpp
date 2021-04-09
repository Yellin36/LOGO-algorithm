#include <iostream>
using namespace std;
int dp[31][31];

int main()
{
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		
		for (int j = 0; j < 32; j++) {
			for (int k = 0; k < 32; k++) {
				dp[j][k] = 0;
			}
		}
		cin >> N >> M;

		for (int j = 1; j <= M; j++) {
			dp[1][j] = j;
		}

		for (int j = 2; j <= N; j++) {
			for (int k = j; k <= M; k++) {
				for (int s = k - 1; s >= j - 1; s--) {
					dp[j][k] += dp[j - 1][s];
				}
			}
		}
		cout << dp[N][M] << endl;
	}
}
