let answer = 0;
function dfs(index, sum, target, numbers) {
  if (index === numbers.length) {
    if (sum === target) answer++;
    return;
  }
  dfs(index + 1, sum + numbers[index], target, numbers);
  dfs(index + 1, sum - numbers[index], target, numbers);
}
function solution(numbers, target) {
  dfs(0, 0, target, numbers);
  return answer;
}
