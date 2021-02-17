let answer = 0;
let parent = [];

const find = (node) => {
  if (node == parent[node]) return node;
  else return (parent[node] = find(parent[node]));
};

function solution(n, costs) {
  costs.sort((a, b) => {
    return a[2] - b[2];
  });
  parent = new Array(costs.length).fill(0).map((a, index) => (a = index));

  for (let i = 0; i < costs.length; i++) {
    console.log(parent);
    let start = find(costs[i][0]);
    let end = find(costs[i][1]);
    let cost = costs[i][2];
    if (start !== end) {
      parent[start] = end;
      answer += cost;
    }
  }

  return answer;
}
