#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> overlay;
	set<string> people;
	set<string>::iterator iter;
	string name;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		people.insert(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		iter = people.find(name);
		if (iter != people.end()) {
			overlay.push_back(name);
		}
	}

	sort(overlay.begin(), overlay.end());
	cout << overlay.size() << endl;
	for (int i = 0; i < overlay.size(); i++) {
		cout << overlay[i] << endl;
	}

	return 0;
}
