function solution(participant, completion) {
    var answer = '';
    let obj = new Object();
   
    obj = participant.reduce((obj, current)=> {
		obj[current] = obj[current] ? obj[current] + 1  : 1;
		return obj; } , {});
    
    completion.map(name =>obj[name] = obj[name] -1);
    Object.keys(obj).map(v=>{
        if(obj[v]>0) answer = v;
    });
   // console.log(answer);
    
    return answer;
}