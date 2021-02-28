function solution(n, results) {
  let answer = 0;
  let graph = Array.from({ length: n }, () => Array(n).fill(false));

  results.map((game) => {
    const [win, lose] = game;
    graph[win - 1][lose - 1] = 1;
    graph[lose - 1][win - 1] = -1;
    graph[lose - 1][lose - 1] = 0;
    graph[win - 1][win - 1] = 0;
  });

  //플로이드 와샬 알고리즘 적용
  for (let k = 0; k < n; k++) {
    //k 중간에 지나는 노드
    for (let i = 0; i < n; i++) {
      //i 출발노드
      for (let j = 0; j < n; j++) {
        //j 도착 노드
        if (graph[i][k] === 0) break;
        if (graph[i][k] === 1 && graph[k][j] === 1) graph[i][j] = 1;
        if (graph[i][k] === -1 && graph[k][j] === -1) graph[i][j] = -1;
      }
    }
  }

  //false가아닌경우의 값의 배열만 필터링
  answer = graph.filter((graph2) => graph2.every((item) => item !== false)).length;

  return answer;
}
