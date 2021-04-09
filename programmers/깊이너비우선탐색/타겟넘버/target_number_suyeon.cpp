#include <string>
#include <vector>
using namespace std;

void dfs(vector<int> numbers, int target, int cnt, int res, int& answer){
    if(cnt == numbers.size())  {
        if(res == target)
            answer++;
        return;
    }
    dfs(numbers, target, cnt+1, res+numbers[cnt], answer);
    dfs(numbers, target, cnt+1, res-numbers[cnt], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}
