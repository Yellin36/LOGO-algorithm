function solution(genres, plays) {
    var answer = [];
    
    let list = genres.reduce((obj,genre,index)=>{
        if(!obj[genre]){
            obj[genre]={plays : plays[index],music:[]};
        } else {
            obj[genre].plays += plays[index];
        }
        obj[genre].music.push([index,plays[index]]);
        return obj;
        
    },{});
    let sortlist = Object.values(list).sort((a,b)=>b.plays-a.plays);
    console.log(sortlist);
    sortlist.forEach((g)=>{
        if(g.music.length>1){
            g.music.sort((a, b)=>{
                if(a[1] >b[1]){
                    return -1;
                } else if(a[1] < b[1]){
                    return 1;
                } else {
                    return (a[0]>b[0]?1:-1);
                }
            });
            answer.push(g.music[0][0]);
            answer.push(g.music[1][0]);
        } else {
            answer.push(g.music[0][0]);
        }
    });
   // console.log(sortlist);
    return answer;
}