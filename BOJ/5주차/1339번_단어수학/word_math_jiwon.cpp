#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    //수는 0~9임
    int N;
    cin>>N;
    
    int arr[27]={0,};
    string tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        int k = 1;
        for(int j = (int)tmp.length()-1;j>=0;j--){
            arr[tmp[j] - 'A'] -=k;
            k *= 10;
        }
    }
    sort(arr, arr+27);
    
    int answer = 0;
    for(int i=0;i<10;i++){
        answer += -arr[i]*(9-i);
    }
    
    cout<<answer<<"\n";

}

