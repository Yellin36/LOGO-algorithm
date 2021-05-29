#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;
    vector<int> a, b;

    scanf("%d", &t);
    while(t--) {
	int sum = 0;
	scanf("%d %d", &n, &m);
	a.resize(n); b.resize(m);
	for(int i=0; i<n; i++) {
	    scanf("%d", &a[i]);
	}
	for(int i=0; i<m; i++) {
	    scanf("%d", &b[i]);
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < n; i++) {
	    int j;
	    for(j = 0; j < m; j++) {
		if(a[i] <= b[j]) break;
	    }
	    sum += j;
	}
	printf("%d\n", sum);
    }
}
