var answer = [];

function solution(progresses, speeds) {
    
    const deploy = progresses.map((progress,index) => {
        return Math.ceil((100 - progress) / speeds[index]);
    });

   let cnt = 0;
   let max = deploy[0]; 
   console.log(`deploy : ${deploy}`);
   
    for(let i=0;i<deploy.length;i++){
        cnt ++;
        if(max < deploy[i+1]){
            answer.push(cnt);
            console.log(cnt);
            cnt = 0 ;
            max = deploy[i+1];
        } else if(i === deploy.length-1){
            answer.push(cnt);
        }
        
        
    }
   
return answer;
   
}