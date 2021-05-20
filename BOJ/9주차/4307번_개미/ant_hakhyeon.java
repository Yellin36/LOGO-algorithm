// BOJ 4307번: 개미
import java.io.*;
import java.util.*;
public class practice01 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		while(TC-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int length = Integer.parseInt(st.nextToken());
			int antCount = Integer.parseInt(st.nextToken());
			int min = 0;
			int max = 0;
			
			for(int i = 0; i < antCount; i++) {
				int ant = Integer.parseInt(br.readLine());
				int antMin = Math.min(ant, length-ant);
				int antMax = Math.max(ant, length-ant);
				
				min = Math.max(min, antMin);
				max = Math.max(max, antMax);
			}
			System.out.println(min + " " + max);
		}
	}
}