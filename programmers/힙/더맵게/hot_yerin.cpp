#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> list;
    
    for(int i=0; i<scoville.size(); i++) list.push(scoville[i]);
    
    for(int top = list.top(); top < K; top = list.top()) {
        if(list.size() == 1) return -1;
        
        list.pop();
        list.push(top + list.top() * 2);
        list.pop();
        answer++;
    }
    return answer;
}
