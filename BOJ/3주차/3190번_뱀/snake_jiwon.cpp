#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

bool board[101][101]; //보드에 뱀
int result = 0;
int N, K, L;
int x, y;  //행, 열
int look = 1;  //0상, 1우, 2하, 3좌
queue<pair<int, char>> direction;
deque<pair<int, int>> snake;


bool Isrange(int x, int y){
    if(x <= 0 || x > N ||  y <= 0 || y > N)
        return false;
    
    for(int i = 0;i<snake.size();i++){
        if(snake[i].first == x && snake[i].second == y)
            return false;
    }
    return true;
}

void Isdirection(){
    switch (look) {
        case 0:  //상
            if (direction.front().second == 'L'){  //왼쪽
                x--;look = 3;
            }
            else{  //오른쪽
                x++;look=1;
            }
            break;
            
        case 1:  //우
            if (direction.front().second == 'L'){  //왼쪽
                y--;look = 0;
            }
            else{  //오른쪽
                y++;look = 2;
            }
            break;
        case 2:  //하
            if (direction.front().second == 'L'){  //왼쪽
                x++;look=1;
            }
            else{  //오른쪽
                x--;look=3;
            }
            break;
        case 3:  //좌
            if (direction.front().second == 'L'){  //왼쪽
                y++;look=2;
            }
            else{  //오른쪽
                y--;look=0;
            }
            break;
    }
}

void Isgo(){
    switch (look) {
        case 0:  //상
            y--;
            break;
            
        case 1:  //우
            x++;
            break;
        case 2:  //하
            y++;
            break;
        case 3:  //좌
            x--;
            break;
    }
}

int main(){
    cin>>N>>K;
    
    //사과 위치 보드에 표기
    for(int i=0;i<K;i++){
        cin>>y>>x;
        board[y][x] = true;
    }
    
    //방향 정보
    cin>>L;
    int time;
    char time_direction;
    for(int i=0;i<L;i++){
        cin>>time>>time_direction;
        direction.push(make_pair(time, time_direction));
    }
    
    /*cout<<"사과 어디 있나"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    
    //sort(direction.begin(), direction.end());
    
    //도스게임 시작
    snake.push_back(make_pair(1, 1));
    x=2;y=1; //1,1에서 시작한다.
    while (Isrange(y,x)) {
        result++;
        //cout<<result<<"초 ("<<y<<","<<x<<") ";
        //사과 판별
        if(board[y][x]){ //사과 있다.
            //cout<<"apple"<<endl;
            //사과를 먹고
            board[y][x] = false;
            //꼬리는 가만히 있고 머리만 움직여
            snake.push_front(make_pair(y, x));
        }
        else{  //사과 없다.
            //cout<<"noo apple"<<endl;
            //머리 추가
            snake.push_front(make_pair(y, x));
            //꼬리 하나 지워
            snake.pop_back();
        }
        //회전 판별하여 다음 x,y값 결정
        if(result == direction.front().first){ //회전이 필요한 시간
            Isdirection();
            direction.pop();
        }
        
        else{
            Isgo();
        }
    }
    cout<<++result<<endl;
}




