#include <iostream>
using namespace std;

double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double solution(int n, int m) {
    return factorial(n) / (factorial(n - m) * factorial(m));
}

int main() {
    int T, n, m;
    cin >> T;
    for (int i=0; i < T; i++)
    {
        cin >> n >> m;
        cout.precision(10);
        cout << solution(m, n) << endl;

    }

}
