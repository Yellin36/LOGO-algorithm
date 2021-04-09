#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //다리에 올라와있는 트럭 정보 확인할 변수
    queue<int> bridge;
    int bridge_weight = 0;
    
    //n번째 트럭인지 확인할 변수
    int truck_front = 0;
    int truck_cur = 0;
    
    while(truck_front != truck_weights.size()){
        if(!bridge.empty() && (answer - bridge.front() == bridge_length)){
            bridge_weight -= truck_weights[truck_front++];
            bridge.pop();
        }
        if(truck_cur != truck_weights.size() && bridge_weight + truck_weights[truck_cur] <= weight){
            bridge_weight += truck_weights[truck_cur++];
            bridge.push(answer);
        }
        answer++;
    }
    
    
    return answer;
}
