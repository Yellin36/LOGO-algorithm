#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { return a > b; }

int main() {
	int T, N, M, doc, top;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		vector<int> priority(N);
		vector<pair<int, int>> print_list(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &doc);
			priority[i] = doc;
			print_list[i] = { doc, i };
		}
		top = 0;
		sort(priority.begin(), priority.end(), compare);
		for (int i = 0; i < print_list.size(); i++) {
			if (priority[top] != print_list[i].first) {
				print_list.push_back(print_list[i]);
				continue;
			}
			top++;
			if (print_list[i].second == M) break;
		}
		printf("%d\n", top);
	}
}
