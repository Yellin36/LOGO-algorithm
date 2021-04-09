function solution(priorities, location) {
    var answer = 0;
    let cnt = 0 ;
    const priority = priorities.map((prior,index)=>({
            index : index,
            value : prior
    }));
    
    while(priority.length>0){    
        
        const current = priority.shift();
        if(priority.some(v => current.value < v.value)){
            priority.push(current);
        } else {
          answer++;
          if(current.index === location) break;
        }

    }
    return answer;
}