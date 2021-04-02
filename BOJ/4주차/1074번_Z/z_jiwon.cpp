#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;   //2의 N승, 행, 열
int answer = 0;


void Z(int x, int y, int size){
    /*if(size == 2){
        //r행c열
        if(x == c && y == r){
            cout<<answer<<"\n";
            return;
        }
        
        //우,하,우하
        answer++;
        if(x + 1 == c && y == r){
            cout<<answer<<"\n";
            return;
        }
        answer++;
        if(x  == c && y + 1 == r){
            cout<<answer<<"\n";
            return;
        }
        answer++;
        if(x + 1 == c && y + 1 == r){
            cout<<answer<<"\n";
            return;
        }
        answer++;
        return;
        
    }*/
    
    if(x == c && y == r){
        cout<<answer<<"\n";
        return;
    }
    if(!(x <= c && c < x + size && y <= r && r < y + size)){
        answer += size * size;
        return;
    }
    
    //1~4사분면
    Z(x, y, size/2);
    Z(x + size/2, y, size/2);
    Z(x, y + size/2, size/2);
    Z(x + size/2, y + size/2, size/2);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>N>>r>>c;
    Z(0,0,pow(2,N));
    
    
}

