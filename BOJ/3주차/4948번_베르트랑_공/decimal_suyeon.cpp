#include <iostream>
using namespace std;

void decimalDiscrimination(int n) {
	int sum = 0;
	if (n == 1) {
		cout << sum+1 << endl;
		return;
	}
	int numArray[246913];

	for (int i = 2; i <= n * 2; i++) {
		numArray[i] = i;
	}

	for (int i = 2; i <= n * 2; i++) {
		if (numArray[i] == 0) continue;

		for (int j = i + i; j <= n * 2; j += i) {
			numArray[j] = 0;
		}
	}

	for (int i = n+1; i <= n * 2; i++) {
		if (numArray[i] != 0) {
			sum++;
		}
	}

	cout << sum << endl;
	return;
}

int main()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;

		decimalDiscrimination(n);
	}
}
