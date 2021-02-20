#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> point;
    int min_move = (int)name.size()-1;
    
    for(int i=0;i<name.size();i++){
        //상하 판별
        answer += name[i] - 'A' < 1 + 'Z' - name[i] ? name[i] - 'A' : 1 + 'Z' - name[i];
        
        int next = i+1;
        // 연속된 A가 있는지를 따져 다음 문자열을 판단
        while(next < name.size() && name[next] == 'A')
            next++;
        // 내 위치에서 첫 위치로 돌아간 후
        // A가 연속으로 나오는 지점 다음을 끝에서 계산하여
        // 기존에 움직인 횟수와 비교
        min_move = min_move > i+name.size()-next+i ? i+name.size()-next+i : min_move;
    }

    return answer + min_move;
}
