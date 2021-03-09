// 프로그래머스 고득점 kit 그래프 - 순위
public class practice01 {
	public int solution(int n, int[][] results) {
        int answer = 0;
        boolean[][] gameResult = new boolean[n][n];
        for(int i = 0; i < results.length; i++) {
        	int winner = results[i][0]-1;
        	int loser = results[i][1]-1;
        	gameResult[winner][loser] = true;
        }
        // floyd-warshall
        for(int i = 0; i < n; i++) { // 경유 노드
        	for(int j = 0; j < n; j++) { // 시작 노드
        		for(int k = 0; k < n; k++) { // 도착 노드
        			if(gameResult[j][i] && gameResult[i][k])
        				gameResult[j][k] = true;
        		}
        	}
        }
        // 카운팅
        for(int i = 0; i < n; i++) {
        	int count = 0;
        	for(int j = 0; j < n; j++) {
        		if(gameResult[i][j] || gameResult[j][i])
        			count++;
        	}
        	if(count == n-1)
        		answer++;
        }        
        return answer;
    }
}
