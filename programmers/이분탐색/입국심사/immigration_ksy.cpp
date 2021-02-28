#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    unsigned long long itmesize = times.size();
    unsigned long long back = times.back();
    unsigned long long mid = 0, num = 0, start = 1, m = n, end = back*m;
    
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
