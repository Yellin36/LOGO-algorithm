#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    long long start = 1;
    ulong long end = times[times.size()-1] * ( long long)n;
    
    while(start<=end){
         long long mid = (start + end) / 2;
         long long cnt = 0;
        
        for(int i=0;i<(int)times.size();i++)
            cnt += mid / times[i];
        
        if(cnt >= n){
            end = mid - 1;
            if(answer == 0)
                answer = mid;
            else{
                answer = min(mid,answer);
            }
        }
        else
            start = mid + 1;
    }
    
    return answer;
}
