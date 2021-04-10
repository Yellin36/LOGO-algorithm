#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main()
{
	stack<int> numStack;
	vector<int> nums;
	vector<char> computation;
	int n, num , k= 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}

	for (int i = 1; i <= n; i++) {
		numStack.push(i);
		computation.push_back('+');

		while (!numStack.empty()) {
			if (nums[k] == numStack.top()) {
				numStack.pop();
				computation.push_back('-');
				k++;
			}
			else
				break;
		}

	}

	if (!numStack.empty()) {
		cout << "NO" << "\n";
		return 0;
	}

	for (int i = 0; i < computation.size(); i++) {
		cout << computation[i] << "\n";
	}
}
