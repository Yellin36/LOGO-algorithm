#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total_weight=0, top = 0;
    queue<int> bridge;

    while(1) {
        if(bridge.size() == bridge_length) {
            if(bridge.front() == -1) break;
            total_weight -= bridge.front();
            bridge.pop();
        }
        if(top < truck_weights.size()) {
            if(total_weight + truck_weights[top] <= weight) {
                total_weight += truck_weights[top];
                bridge.push(truck_weights[top++]);
            }
            else bridge.push(0);
        }
        else bridge.push(-1);
        answer++;
    }
    return answer;
}
