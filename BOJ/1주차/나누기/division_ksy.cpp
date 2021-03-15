#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    int n, f;
    int answer = 0;

    cin >> n >> f;

    answer = (n / 100) * 100;

    for (int i = answer; i < (answer + 100); i++)
    {
        if (i % f == 0) {
            answer = i % 100;
            break;
        }
    }

        cout.width(2);
        cout.fill('0');
        cout << answer;

}
