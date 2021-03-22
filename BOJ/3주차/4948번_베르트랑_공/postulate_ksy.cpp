#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution(int n) {
    bool* answer;
    int m = n * 2, j = 1, x = sqrt(m);
    answer = new bool[m+1];
    
    for (int i = 1; i <= m; i++) {
        answer[i] = 1;
    }
    for (int i = 2; i <= x; i++) {
        while(j*i <= m){
            answer[j * i] = 0;
            j++;
        }
        j = 1;
    }
    j = 0;
    for (int i = n+1; i <= m; i++){
        if (answer[i] == 1) {
            j++;
        }
    }
    cout << j << endl;
}

int main() {
    int T = 1;
    while (T >= 1){
        cin >> T;
        if (T != 0) solution(T);
    }
    return 0;
}
