function solution(n, times) {
  let answer = Infinity;
  times.sort((a, b) => {
    return a - b;
  });

  let left = 1;
  let right = times[times.length - 1] * n;
  while (left <= right) {
    let middle = Math.floor((left + right) / 2);
    let count = 0;
    times.forEach((time) => {
      count += parseInt(middle / time);
      if (count >= n) answer = Math.min(answer, middle);
    });

    if (count >= n) right = middle - 1;
    else left = middle + 1;
  }
  return answer;
}
