#include <iostream>
#include <vector>

using namespace std;

int N, K,S;
int arr[401][401] = {{0,},};

void Floyd(){
    for(int i=1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(arr[j][k] == 0){
                    if(arr[j][i] == 1 && arr[i][k] == 1){
                        arr[j][k] = 1;
                    }
                    else if(arr[j][i] == -1 && arr[i][k] == -1){
                        arr[j][k] = -1;
                    }
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>K;
    
    int a, b;
    for(int i=0;i<K;i++){
        cin>>a>>b;
        arr[a][b] = -1;
        arr[b][a] = 1;
    }
    
    Floyd();
    
    cin>>S;
    for(int i=0;i<S;i++){
        cin>>a>>b;
        cout<<arr[a][b]<<'\n';
    }
}

