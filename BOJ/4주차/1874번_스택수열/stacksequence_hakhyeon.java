// BOJ 1874번: 스택수열
import java.io.*;
import java.util.*;
public class practice05 {
	static Stack<Integer> stack = new Stack<>();
	static int count = 1;
	static boolean temp = true;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder op = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			int num = Integer.parseInt(br.readLine());
			while(count <= num) {
				stack.add(count);
				op.append("+\n");
				count += 1;
			}
			if(stack.peek() == num) {
				stack.pop();
				op.append("-\n");
			}
			else
				temp = false;
		}
		if(!temp)
			System.out.println("NO");
		else
			System.out.println(op);
	}
}