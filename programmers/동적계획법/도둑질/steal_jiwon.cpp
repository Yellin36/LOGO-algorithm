#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> first_start(money.size(),0);
    vector<int> second_start(money.size(),0);
    
    first_start[0] = money[0];
    first_start[1] = money[0];
    second_start[1] = money[1];
    
    for(int i=2;i<money.size()-1;i++){
        first_start[i] = max(first_start[i-2] + money[i], first_start[i-1]);
        second_start[i] = max(second_start[i-2] + money[i], second_start[i-1]);
    }
    second_start[money.size()-1] = max(second_start[money.size()-3] + money.back(), second_start[money.size()-2]);
    
    return answer=max(first_start[money.size()-2],second_start[money.size()-1]);
}
