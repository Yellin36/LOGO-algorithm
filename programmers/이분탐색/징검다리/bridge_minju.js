function solution(distance, rocks, n) {
  let answer = 0;
  rocks.sort((a, b) => a - b);

  let left = 1;
  let right = distance;
  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    let removed = 0;
    let last = 0;
    for (let i = 0; i < rocks.length + 1; i++) {
      const dist = i != rocks.length ? rocks[i] - last : distance - rocks[i - 1];
      if (dist < mid) {
        removed = removed + 1;
      } else if (i != rocks.length) {
        last = rocks[i];
      }
    }

    if (removed > n) {
      right = mid - 1;
    } else {
      left = mid + 1;
      answer = mid;
    }
  }
  return answer;
}
