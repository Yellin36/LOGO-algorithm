// 프로그래머스 고득점 kit DFS/BFS - 타겟넘버
public class practice01 {
	public int solution(int[] numbers, int target) {
        int answer = 0;
        answer = dfs(numbers, 0, 0, target);
        return answer;
    }
	public int dfs(int[] numbers, int index, int sum, int target) {
		if(index == numbers.length) {
			if(sum == target)
				return 1;
			return 0;
		}
		return dfs(numbers, index+1, sum+numbers[index], target)
				+ dfs(numbers, index+1, sum-numbers[index], target);
	}
}
