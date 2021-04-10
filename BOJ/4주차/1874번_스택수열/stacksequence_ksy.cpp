#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int x, max = 0, n = 0, y;
    string pm = "";
    stack<int> answer;
    
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> y;
        if(y > max){
            max = y;
        }
        if(y >= max){
            while(n < max){
                n++;
                answer.push(n);
                pm += "+\n";
            }
            answer.pop();
            pm += "-\n";
        }
        else{
            if(answer.empty() || answer.top() < y) {
                cout << "NO\n";
                return 0;
            }
            while(y <= answer.top()){
                answer.pop();
                pm += "-\n";
                if(answer.empty()) break;
            }
        }
    }
    cout << pm;
    
}

