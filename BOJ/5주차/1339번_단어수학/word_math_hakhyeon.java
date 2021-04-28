// BOJ 1339번: 단어 수학
import java.io.*;
import java.util.*;
public class practice03 {
    static char[] alphabet;
    static int[] sum;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        alphabet = new char[10];
        sum = new int[10];
        Arrays.fill(alphabet, '0');
        Arrays.fill(sum, 0);
        for(int i = 0; i < N; i++) {
            String input = br.readLine();
            int w = 1; // 자릿 수
            
            // 거꾸로 접근해야 일의 자리 수 부터 계산 가능
            for(int j = input.length() - 1; j >= 0; j--) {
                char numChar = input.charAt(j);
                
                for(int k = 0; k < 10; k++) {
                    if(alphabet[k] == numChar) {
                        sum[k] += w;
                        break;
                    } else if(alphabet[k] == '0') {
                        alphabet[k] = numChar;
                        sum[k] = w;
                        break;
                    }
                }
                w *= 10;
            }
        }
        Arrays.sort(sum);
        int result = 0;
        
        for(int i = 9; i >= 0; i--)
            result += i * sum[i];
        System.out.println(result);
    }
}