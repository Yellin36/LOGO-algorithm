#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    string number, temp;
    int result = 0, T = 0;

    cin >> number;

    for (int i = 0; i <= number.size(); i++){
        if (number[i] == '+' || number[i] == '-' || i == number.size()) {
            if (T) {
                result -= stoi(temp);
            }
            else {
                result += stoi(temp);
            }
            if (number[i] == '-') {
                T = 1;
            }
            temp = "";
            continue;
        }
            temp += number[i];
        
    }

    
    cout <<result;
    
    return 0;
}

