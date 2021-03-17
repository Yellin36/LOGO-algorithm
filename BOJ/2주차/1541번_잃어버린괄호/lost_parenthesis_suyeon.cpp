#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numericalExpression;
	cin >> numericalExpression;
	string tmp;
	int sum = 0, flag = 0;

	for (int i = 0; i <= numericalExpression.size(); i++) {
		if (numericalExpression[i] == '+' || numericalExpression[i] == '-' || i == numericalExpression.size()) {
			if (flag)
				sum -= stoi(tmp);
			else
				sum += stoi(tmp);

			if (numericalExpression[i] == '-')
				flag = 1;

			tmp.erase();
		}
		else
			tmp += numericalExpression[i];
	}

	cout << sum;
}
