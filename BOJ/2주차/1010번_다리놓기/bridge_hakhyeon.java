// BOJ 1010번: 다리 놓기
import java.io.*;
import java.util.*;
public class practice02 {
	public static int dp[][] = new int[30][30];
	public static int combination(int n, int r) {
		if(dp[n][r] != 0) return dp[n][r];
		if(n == r || r == 0) return 1;
		else {
			dp[n][r] = combination(n-1, r-1) + combination(n-1, r);
			return dp[n][r];
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			System.out.println(combination(M, N));
		}
	}
}
