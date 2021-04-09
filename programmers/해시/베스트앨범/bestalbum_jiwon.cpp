#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    if(a.first < b.first)
        return false;
    else if(a.first == b.first && a.second > b.second)
        return false;
    return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genres_sum;   //장르, 총 합
    map<string,vector<pair<int, int>>> play_info;  //장르, 재생수, 고유번호

    //정보 저장
    for(int i=0;i<genres.size();i++){
        genres_sum[genres[i]] += plays[i];
        play_info[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    //가장 많이 재생된 장르
    vector<pair<int, string>> genre;
    for(auto p : genres_sum)
        genre.push_back(make_pair(p.second, p.first));
    sort(genre.begin(),genre.end());
    
    //장르별로 최대 2개씩 골라내기
    while(genre.size()){
        vector<pair<int, int>> play_tmp = play_info[genre.back().second];
        genre.pop_back();
        
        //장르에 하나의 노래만 들어있을 경우
        if(play_tmp.size() == 1){
            answer.push_back(play_tmp[0].second);
            continue;
        }
        else{
            sort(play_tmp.begin(),play_tmp.end(),compare);
            answer.push_back(play_tmp[0].second);
            answer.push_back(play_tmp[1].second);
        }
        
    }
    
    
    return answer;
}
