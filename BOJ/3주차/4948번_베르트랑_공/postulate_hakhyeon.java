// BOJ 4948번: 베르트랑 공준
import java.io.*;
public class practice04 {
	public static boolean[] prime = new boolean[246913];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		prime_number();
		while(true) {
			int N = Integer.parseInt(br.readLine());
			if(N == 0) break;
			int count = 0;
			for(int i = N+1; i <= 2*N; i++) {
				if(!prime[i]) count++;
			}
			bw.write(count + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void prime_number() {
		prime[0] = prime[1] = true;
		for(int i = 2; i <= Math.sqrt(prime.length); i++) {
			if(prime[i]) continue;
			for(int j = i * i; j < prime.length; j += i) {
				prime[j] = true;
			}
		}
	}
}
