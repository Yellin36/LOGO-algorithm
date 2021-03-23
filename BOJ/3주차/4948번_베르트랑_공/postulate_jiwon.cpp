#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

bool PrimeArray[123456 * 2];  //default false
int result = 0;

void Eratos(int n){
    for(int i = 2;i<= n;i++){
        if(PrimeArray[i]){
            for(int j = i + i; j<= 2 * n;j+=i){
                PrimeArray[j] = false;
            }
        }
    }
}


int main(){
    int n;
    while(true){
        cin>>n;
        if(n == 0)
            break;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        result = 0;
        memset(PrimeArray, true, 123456*2);
        
        Eratos(n);
        
        for(int i = n+1;i<= 2 * n;i++){
            if(PrimeArray[i]){
                result++;
            }
        }
        cout<<result<<endl;
    }
}

