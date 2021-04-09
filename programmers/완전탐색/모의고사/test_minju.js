function solution(answers) {
  const test1 = [1, 2, 3, 4, 5];
  const test2 = [2, 1, 2, 3, 2, 4, 2, 5];
  const test3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let answer = [];
  let count = [0, 0, 0];

  answers.map((curr, index) => {
    if (curr === test1[index % test1.length]) count[0]++;
    if (curr === test2[index % test2.length]) count[1]++;
    if (curr === test3[index % test3.length]) count[2]++;
  });

  const max = Math.max(count[0], count[1], count[2]);

  for (let i = 0; i < 3; i++) {
    if (max === count[i]) answer.push(i + 1);
  }

  return answer;
}
