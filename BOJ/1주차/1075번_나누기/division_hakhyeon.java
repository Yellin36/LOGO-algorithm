// BOJ 1075번: 나누기
import java.io.*;
public class practice03 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int F = Integer.parseInt(br.readLine());
        int temp = (N/100) * 100;
        while(true) {
            if(temp % F == 0) {
                int result = temp % 100;
                if(result < 10)
                    System.out.println("0" + result);
                else
                    System.out.println(result);
                return;
            }
            temp++;
        }
	}
}
