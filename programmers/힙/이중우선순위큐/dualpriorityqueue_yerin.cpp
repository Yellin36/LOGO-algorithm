#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    int cnt = 0, num;
    priority_queue<int, vector<int>> decre;
    priority_queue<int, vector<int>, std::greater<int> > incre;
    
    for(int i = 0; i < operations.size(); i++) {
        num = stoi(operations[i].substr(2));
        switch(operations[i][0]) {
            case 'I':
                decre.push(num);
                incre.push(num);
                break;
            case 'D':
                bool size = (decre.size() - cnt) > 0;
                if(num == 1 && size) {
                    decre.pop();
                }
                else if(num == -1 && size) {
                    incre.pop();
                    cnt++;
                }
                break;
        }
        if(decre.size() - cnt == 0) {
            priority_queue<int, vector<int>> tmp1;
            priority_queue<int, vector<int>, greater<int>> tmp2;
            decre.swap(tmp1);
            incre.swap(tmp2);
            cnt = 0;
        }
    }
    if(decre.size() - cnt == 0) return {0, 0};
    return {decre.top(), incre.top()};
}
