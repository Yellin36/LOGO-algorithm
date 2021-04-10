#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, top = 1, cnt = 0, num[100005];
    char opt[100005];
    bool err = false;

    scanf("%d", &n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    } s.push_back(0);

    for (int i = 0; i < n;) {
        if (num[i] > s.back()) {
            if (top == n + 1) {
                err = true;  
                break;
            }
            opt[cnt++] = '+';
            s.push_back(top++);
        }
        else {
            if (num[i] == s.back()) i++;
            opt[cnt++] = '-';
            s.pop_back();
        }
    }
    if(err) printf("NO\n"); 
    else {
        for (int i = 0; i < cnt; i++)
            printf("%c\n", *(opt + i));
    }
}
