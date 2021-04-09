#include <iostream>
using namespace std;

int main()
{
	long long int n;
	int m;
	cin >> n >> m;

	n -= (n % 100);

	while (true) {
		if (n % m == 0)
			break;
		else {
			n++;
		}
	}

	n %= 100;
	if (n < 10)
		cout << 0 << n;
	else
		cout << n;
}
