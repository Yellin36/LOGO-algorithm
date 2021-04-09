#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=3;i<=brown+yellow;i++){
        int n = (brown + yellow) / i;
        if(n && n>= i && (n-2)*(i-2) >= yellow){
            answer.push_back(n);
            answer.push_back(i);
            return answer;
        }
    }
    return answer;
}
