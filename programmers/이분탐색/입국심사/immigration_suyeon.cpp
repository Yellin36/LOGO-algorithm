#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0, right = (long long)times[times.size()-1] * (long long)n, sum;
    
    while(left <= riㅁght) {
        sum = 0;
        long long mid = (left+right) / 2;
        
        for(int i = 0; i < times.size(); i++) 
            sum += mid / times[i];
        
        if(n <= sum) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
        
    }
    
    
    return answer;
}
