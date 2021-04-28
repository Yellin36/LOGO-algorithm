// BOJ 1057번: 토너먼트
import java.io.*;
import java.util.*;
public class practice02 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int N = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int count = 0;
		while(true) {
			count += 1;
			a = (a / 2) + (a % 2);
			b = (b / 2) + (b % 2);
			if(a == b) break;
		}
		System.out.println(count);
	}
}