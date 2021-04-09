#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height;
    int sum = brown + yellow;
    for(int i = sum; i >=1; i--) {
        if(sum % i == 0) {
            height = sum / i;
            if(i < height)
                break;
            if((i - 2)*(height - 2) == yellow) {
                answer.push_back(i);
                answer.push_back(height);
            }
        }
    }
    return answer;
}
