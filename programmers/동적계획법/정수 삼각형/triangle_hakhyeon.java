// 프로그래머스 고득점 kit 동적계획법 - 정수 삼각형
public class practice04 {
	public static int solution(int[][] triangle) {
		int answer = 0;
		int temp = 0;
		int[][] dp = new int[triangle.length][triangle.length];
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.length; i++) {
		    dp[i][0] = dp[i-1][0] + triangle[i][0]; // 왼쪽 끝 값
		    dp[i][i] = dp[i-1][i-1] + triangle[i][i]; // 오른쪽 끝 값
		}
		for(int i = 2; i < triangle.length; i++) {
			for(int j = 1; j < i; j++) {
				dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
			}
		}
		for(int i = 0; i < triangle.length; i++) { // 삼각형의 바닥부분 중에서(경로합) 가장 큰거 골라 리턴시키기
			if(dp[triangle.length-1][i] > temp)
				temp = dp[triangle.length-1][i];
		}
		answer = temp;
        return answer;
    }
	public static void main(String[] args) {
		int[][] triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
		int answer = solution(triangle);
		System.out.println(answer);
	}
}