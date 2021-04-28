// BOJ 1074번: Z
import java.io.*;
import java.util.*;
public class practice03 {
	static int N, r, c, count;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		solution((int)Math.pow(2, N), 0, 0);
	}
	
	public static void solution(int n, int y, int x) {
		if(y == r && x == c) {
			System.out.println(count);
			return;
		}
		if(y <= r && r < (y+n) && x <= c && c < (x+n)) {
			int divideN = n / 2;
			solution(divideN, y, x);
			solution(divideN, y, x+divideN);
			solution(divideN, y+divideN, x);
			solution(divideN, y+divideN, x+divideN);
		} else
			count += n * n;
	}
}
