#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution(int n) {
	int m = n * 2, j = 1;
	vector<bool> answer(m + 1, true);

	for (int i = 2; i <= (int)sqrt(m); i++) {
		if(answer[i] == true){
		j = 2;
		while(j*i <= m){
				answer[j * i] = 0;
				j++;
			}	
		}
	}
	j = 0;
	for (int i = n+1; i <= m; i++){
		if (answer[i] == 1) {
			j++;
		}
	}
	cout << j << endl;
}

int main() {
    int T = 1;
	while (T >= 1){
		cin >> T;
		if (T != 0) solution(T);
	}
	return 0;
}
