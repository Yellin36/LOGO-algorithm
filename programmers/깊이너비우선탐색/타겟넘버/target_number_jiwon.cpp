#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int num, int i, vector<int> numbers, int target){
    if(i == (int)numbers.size()){
        if(num == target)
            answer++;
        return;
    }

    DFS(num + numbers[i],i+1,numbers, target);
    DFS(num - numbers[i],i+1,numbers, target);
    
    return;
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers[0],1,numbers,target);
    DFS(-numbers[0],1,numbers,target);
    return answer;
}
