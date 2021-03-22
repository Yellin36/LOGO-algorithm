// BOJ 1541번: 잃어버린 괄호
import java.io.*;
import java.util.*;
public class practice01 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sum = Integer.MAX_VALUE;
		StringTokenizer sub = new StringTokenizer(br.readLine(),"-");
		while(sub.hasMoreTokens()) {
			int temp = 0;
			StringTokenizer add = new StringTokenizer(sub.nextToken(),"+");			
			while(add.hasMoreTokens()) {
				temp += Integer.parseInt(add.nextToken());
			}
			if(sum == Integer.MAX_VALUE)
				sum = temp;
			else
				sum -= temp;
		}
		System.out.println(sum);
	}
}
