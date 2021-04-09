let visit = [];

function dfs(start, computers, n) {
  visit[start] = 1;

  for (let i in computers) {
    if (!visit[i] && computers[start][i] === 1) {
      dfs(i, computers, n);
    }
  }
}
function solution(n, computers) {
  let answer = 0;

  /*
    [1,1,0]
    [1,1,0]
    [0,0,1]*/
  computers.map((computer, index) => {
    if (!visit[index]) {
      dfs(index, computers, n);
      answer++;
    }
  });
  return answer;
}
