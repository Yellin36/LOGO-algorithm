#include <iostream>
using namespace std;
int main() {
    int n, kim, lim;
    scanf("%d %d %d", &n, &kim, &lim);

    n = 0;
    while(kim != lim) {
        kim = (kim + 1) / 2;
        lim = (lim + 1) / 2;
        n++;   
    }
    printf("%d", n);
}
