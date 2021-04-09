#include <iostream>
#include <algorithm>

using namespace std;

int N;
int home[1001][3], sum[1001][3];

void solution() {
	for (int i = 1; i <= N; i++)
	{
		sum[i][0] = min(home[i][0] + sum[i-1][1], home[i][0] + sum[i-1][2]);
		sum[i][1] = min(home[i][1] + sum[i-1][0], home[i][1] + sum[i-1][2]);
		sum[i][2] = min(home[i][2] + sum[i-1][0], home[i][2] + sum[i-1][1]);
	}
	cout << min({ sum[N][0], sum[N][1], sum[N][2] });
}
int main()
{
    cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> home[i][0] >> home[i][1] >> home[i][2];
	}
    solution();
}
