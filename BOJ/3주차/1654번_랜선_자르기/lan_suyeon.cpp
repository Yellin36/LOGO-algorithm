#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long int K, N, max = 0, cnt = 0;
	cin >> K >> N;
	vector<int> lan;

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		if (max < num)	max = num;
		lan.push_back(num);
	}

	long long int left = 1, mid = 0, right = max;

	while (right - left >= 0) {
		mid = (left + right) / 2;
		cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += (lan[i] / mid);
		}
		
		if (cnt >= N)
			left = mid + 1;
		else		
			right = mid - 1;
		
	}

	cout << right << endl;
}
