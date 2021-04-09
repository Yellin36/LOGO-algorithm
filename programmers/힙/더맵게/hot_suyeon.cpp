#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, low1Sco, low2Sco, cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(true) {
        cnt++;
        low1Sco = pq.top(); pq.pop();
        low2Sco = pq.top() * 2; pq.pop();
        
        pq.push(low1Sco+low2Sco);

        if(pq.size() < 2 && pq.top() < K)
            break;
        
        if(pq.top() >= K) {
            answer = cnt;
            break;
        }
    }

    if(pq.top() < K)
        answer = -1;
    
    return answer;
}
