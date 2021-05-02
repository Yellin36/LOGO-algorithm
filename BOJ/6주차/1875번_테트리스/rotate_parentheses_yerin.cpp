#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0, size = s.size();
    while(size--) {
        bool exit = true;
        stack<char> a;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') a.push(s[i]);
            else {
                if (a.empty()) {
                    exit = false;
                    break;
                }
                switch (s[i]) {
                case ')':
                    if (a.top() == '(') a.pop();
                    else exit = false;
                    break;
                case '}':
                    if (a.top() == '{') a.pop();
                    else exit = false;
                    break;
                case ']':
                    if (a.top() == '[') a.pop();
                    else exit = false;
                    break;
                }
            }
            if (!exit) break;
        }
        if (a.empty() && exit) answer++;
        char b = s[0];
        s = s.substr(1, s.size() - 1) + b;
    }
    return answer;
}
