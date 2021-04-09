#include <iostream>
#include <bitset>

using namespace std;

bitset<10000010> bs;
int result = 0;

void Eratos(int n){
    for(int i = 2;i<= n;i++){
        if(bs[i]){
            for(int j = i + i; j<= 2 * n;j+=i){
                bs[j] = 0;
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
        bs.set(); //모든 비트를 1로 설정
        bs[0] = bs[1] = 0; //0과 1은 예외
        
        Eratos(n);
        
        for(int i = n+1;i<= 2 * n;i++){
            if(bs[i]){
                result++;
            }
        }
        cout<<result<<endl;
    }
}

