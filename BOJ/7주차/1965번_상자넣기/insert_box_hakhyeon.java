// BOJ 1965번: 상자넣기
import java.io.*;
import java.util.*;
public class practice02 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int size[] = new int[n];
		int dp[] = new int[n];
		int max = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			size[i] = Integer.parseInt(st.nextToken());
			dp[i] = 1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(size[j] < size[i])
					dp[i] = Math.max(dp[i], dp[j] + 1);
			}
			max = Math.max(max, dp[i]);
		}
		System.out.println(max);
	}
}