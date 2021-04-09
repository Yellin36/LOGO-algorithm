#include<iostream>
using namespace std;
int main() {
    int t, n, m; 
    scanf("%d", &t);
    while (t--) {
	int d[30][30] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= m; i++) d[1][i] = i;
	for (int i = 2; i <= n; i++)
   	    for (int j = i; j <= m; j++)
		for (int k = j; k >= i; k--)
		    d[i][j] += d[i - 1][k - 1];
	printf("%d\n", d[n][m]);
    }
}
