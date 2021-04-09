#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long k, n, start;
int result = 0, answer = 0;
int tape[10000];

void solution() {
    sort(tape, tape + k, greater<int>());
    start = 1;
    long long end = tape[0];
    while (start <= end) {
        long long mid = (start + end) / 2;
            for (int i = 0; i < k; i++)
            {
                result += tape[i] / mid;
            }
            if (result < n)
            {
                end = mid - 1;
            }
            else {
                if (answer < mid) answer = mid;
                    start = mid + 1;
            }
            result = 0;
    }
    cout << answer;
}

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> tape[i];
    }
    solution();
}
