function solution(array, commands) {
    // console.log(array)
    
      var answer = [];
      
     for(var i = 0 ; i <commands.length ; i++ ){
       var  temp = array.slice(commands[i][0]-1,commands[i][1]).sort(function(a,b){return a-b});
      answer.push( temp[commands[i][2]-1]);
     
     }
      console.log(answer);
      return answer;
      
  }