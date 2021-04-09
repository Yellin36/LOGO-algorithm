class Solution {
    public int answer = 0;
    public void dfs(int num, int i, int[] numbers, int target) {
        if(i == numbers.length) {
            if(target == num) answer++;
            return;
        }
        dfs(num + numbers[i], i+1, numbers, target);
        dfs(num - numbers[i], i+1, numbers, target);
    }
    
    public int solution(int[] numbers, int target) {
        dfs(0, 0, numbers, target);
        
        return answer;
    }
}
