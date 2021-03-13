// BOJ 1757번: 달려달려
import java.io.*;
import java.util.*;
public class practice12 {
	static ArrayList<Integer> d = new ArrayList<>();
	static int N, M;
	static int dp[][] = new int[10001][501];
	static int solution(int pos, int m) {
		if(pos == N - m) return 0;
		if(pos > N - m) return -99999999;
		if(dp[pos][m] >= 0) return dp[pos][m];
		int ret = 0;
		if(m < M) {
			if(m > 0)
				ret = Math.max(solution(pos+1, m+1) + d.get(pos), solution(pos+m, 0));
			else if(m == 0)
				ret = Math.max(solution(pos+1, m+1) + d.get(pos), solution(pos+1, 0));
		}
		else if(m == M)
			ret = solution(pos+m, 0);
		return dp[pos][m] = ret;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N; i++) {
			int distance = Integer.parseInt(br.readLine());
			d.add(distance);
			Arrays.fill(dp[i], -1);
		}
		System.out.println(solution(0,0));
	}
}
