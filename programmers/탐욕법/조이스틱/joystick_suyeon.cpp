#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0, flag = 0, firidx, lastidx = 0, tmp = 0, flag2 = 0, tmp1 =0;
    
    for(int i = 0; i < name.size(); i++) {
        if(flag == 1) {
            break;
        }
        if(name[i] >= 'O') {
            for(int j = 'Z'; j >= 'O'; j--) {
                answer++;
                if(name[i] == j)
                    break;
            }
            //cout << answer << endl;
            if(i != name.size()-1 && name[i+1] == 'A' && i+1 <= name.size()/2) {
                flag = 1;
                firidx = i;
                for(int j = i; i >= 0; i--) {
                    answer++;
                }
                break;
            }
        }
        else if(name[i] == 'A' && i <= name.size()/2) {
            flag = 1;
            firidx=i;
            if(name[name.size()-1] != 'A') {
                for(int j = i; i >= 0; i--) {
                    answer++;
                }   
            }
        }
        else if(name[i] != 'A' && name[i] <= 'N') {
            for(int j = 'B'; j <= 'N'; j++) {
                answer++;
                if(name[i] == j)
                    break;
            }
            if(i != name.size()-1 && name[i+1] == 'A' && i+1 <= name.size()/2) {
                flag = 1;
                firidx = i;
                for(int j = i; i >= 0; i--) {
                    answer++;
                }
                break;
            }
        }
        else if(name[i] == 'A' && i > name.size() / 2) {
            continue;
        }
        if(i != name.size()-1 && flag == 0 /*&& name[name.size()-1] != 'A'*/)
            answer++;
        //cout << answer << endl;
    }
    //cout << answer << endl;
    
    if(flag == 1) {
        for(int i = name.size()-1; i > firidx; i--) {
            if(name[i] >= 'O') {
                for(int j = 'Z'; j >= 'O'; j--) {
                    answer++;
                    if(name[i] == j)
                        break;
                }
                if(i != firidx+1 || name[i-1] != 'A')
                    answer++;
                else {
                    for(int k = i; k > firidx; k--) {
                        flag2 = 1;
                        tmp++;
                        if(name[k] != 'A') {
                            answer += tmp;
                            break;
                        }
                    }
                }
            }
            else if(name[i] != 'A' && name[i] <= 'N') {
                for(int j = 'B'; j <= 'N'; j++) {
                    answer++;
                    if(name[i] == j)
                        break;
                }
                if(i != firidx+1 && name[i-1] != 'A') {
                    answer++;   
                }
                else {
                    for(int k = i; k > firidx; k--) {
                        flag2 = 1;
                        tmp++;
                        if(name[k] != 'A') {
                            answer += tmp;
                            break;
                        }
                    }
                }
            }
            else if(name[i] == 'A') {
                for(int j = firidx+1; j < i; j++) {
                    if(name[j] != 'A')
                        lastidx = j;
                }
                continue;
            }
            
            //cout << name[firidx+1] << endl;
            //if(name[firidx+1] != 'A')
                //answer++;
            /*if(i != firidx+1 && name[i-1] != 'A')
                answer++;*/
        }
    }
    if(flag2 == 1)
        answer--;
    
    return answer;
}
