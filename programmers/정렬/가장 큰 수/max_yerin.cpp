#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    for(auto i : numbers) {
        tmp.push_back(to_string(i));
    }
    sort(tmp.begin(), tmp.end(), compare);
    for(auto i : tmp) {
        answer += i;
    }
    return (answer[0] == '0') ? "0" : answer;
}
