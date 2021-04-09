// 프로그래머스 고득점 kit 해시 - 전화번호 목록
import java.util.*;
public class practice01 {
	public static boolean solution(String[] phone_book) {
		boolean answer = true;
		Arrays.sort(phone_book);
		for (int i=0; i<phone_book.length-1; i++){
            for (int j=i+1; j<phone_book.length; j++){
                if (phone_book[i].length() > phone_book[j].length()){
                    if (phone_book[i].substring(0, phone_book[j].length()).equals(phone_book[j])){
                        return false;
                    }
                } else if (phone_book[i].length() < phone_book[j].length()){
                    if (phone_book[j].substring(0, phone_book[i].length()).equals(phone_book[i])){
                        return false;
                    }
                } else{
                    if (phone_book[i].equals(phone_book[j])){
                        return false;
                    }
                }
            }
        }
        return answer;
	}
	public static void main(String[] args) {
		String[] phone_book = {"123", "456", "789"};
		// String[] phone_book = {"119", "97674223", "1195524421"};
		boolean answer = solution(phone_book);
		System.out.println(answer);
	}
}