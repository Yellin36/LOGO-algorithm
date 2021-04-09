#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> chk;
    for(auto i : participant) {
        chk[i]++;
    }
    for(auto i : completion) {
        chk[i]--;
        if(chk[i] == 0) chk.erase(i);
    }
    answer = chk.begin()->first;

    return answer;
}
