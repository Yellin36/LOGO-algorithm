#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--) {
		int numOfClo, sum = 1; cin >> numOfClo;
		unordered_map<string, int> fashionKing;
		for (int i = 0; i < numOfClo; i++) {
			string clothes, kindOfClo;
			cin >> clothes >> kindOfClo;

			if (fashionKing.find(kindOfClo) == fashionKing.end()) {
				fashionKing.insert(make_pair(kindOfClo, 1));
			}
			else {
				fashionKing[kindOfClo]++;
			}
		}

		for (auto i : fashionKing) {
			sum *= (i.second + 1);
		}
		sum -= 1;
		cout << sum << endl;
	}
}
