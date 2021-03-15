#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, f;
	cin >> n >> f;
	string c = to_string(((n - (n % 100) - 1) / f + 1) * f);
	cout << c.substr(c.size()-2);
}
