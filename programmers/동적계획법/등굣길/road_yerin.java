class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] map = new int[n+1][m+1];

        for(int i = 0 ; i < puddles.length; i++) 	// 장애물 설치
            map[puddles[i][1]][puddles[i][0]] = -1;
        
        map[0][1] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                map[i][j] = (map[i][j] == -1) ? 0 : (map[i-1][j] + map[i][j-1])%1000000007;
            }
        }
        return map[n][m]%1000000007;
    }
}
