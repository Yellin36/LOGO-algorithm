#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer, min, max;

    sort(times.begin(), times.end());
    
    min = 1; 
    answer = max = (long long)times[times.size() - 1] * n;
    
    while(min <= max) {
        long long mid = (min + max) / 2, cnt = 0;
        for(auto i : times) {
            cnt += mid / i;
        }
        if(cnt < n) min = mid + 1;
        else {
            if(mid < answer) answer = mid;
            max = mid - 1;
        }
    }
    return answer;
}
