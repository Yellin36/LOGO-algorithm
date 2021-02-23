#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long itmesize = times.size();
    long long end = times.back() * n;
    long long start = (n * times.front()) / itmesize;
    long long mid = 0;
    long long num = 0;
    while (start <= end) {
        num = 0;
        mid = (end + start) / 2;
        for (int i = 0; i < itmesize; i++)
        {
            num += mid / times[i];
        }
            if (num < n) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
                answer = mid;
            }
    }
    return answer;
}
