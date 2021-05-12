#include <iostream>

using namespace std;

int box[1005] = { 0 }, dp_cnt[1005] = { 0 };
int main() {
	int n, answer = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &box[i]);
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i] && dp_cnt[j] + 1 > dp_cnt[i]) {
				dp_cnt[i] = dp_cnt[j] + 1;
			}
		}
		if (answer < dp_cnt[i]) answer = dp_cnt[i];
	}
	printf("%d", answer + 1);
}
