#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num = 9, sum = 1, result = 0;
int alpha[27], N;
string input;

bool desc(int a, int b) {
	return a < b;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = input.length() - 1; j >= 0; j--)
		{
			alpha[input[j] - 'A'] += sum;
			sum *= 10;
		}
		sum = 1;
	}

	sort(alpha, alpha + 27, desc);

	for (int i = 26; i >= 0; i--)
	{
		if (alpha[i] != 0) {
			alpha[i] *= num;
			result += alpha[i];
			num--;
			if (num == 0) break;
		}
	}
	cout << result;
	return 0;
}