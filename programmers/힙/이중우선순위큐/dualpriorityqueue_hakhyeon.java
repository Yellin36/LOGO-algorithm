// 프로그래머스 고득점 kit 힙 - 이중우선순위큐
import java.util.*;
public class practice03 {
	public static int[] solution(String[] operations) {
        int[] answer = {0,0};
        PriorityQueue<Integer> pqMax = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> pqMin = new PriorityQueue<>();

        for (String operation : operations) {
            String[] splitOther = operation.split(" ");

            if (splitOther[0].equals("I")) {
                pqMax.add(Integer.parseInt(splitOther[1]));
                pqMin.add(Integer.parseInt(splitOther[1]));
            }

            if (splitOther[0].equals("D")) {
                if (!pqMax.isEmpty()) {
                    if (splitOther[1].equals("1")) {
                        int max = pqMax.peek();
                        pqMax.remove(max);
                        pqMin.remove(max);

                    } else {
                        int min = pqMin.peek();
                        pqMax.remove(min);
                        pqMin.remove(min);
                    }
                }
            }

        }
        if (!pqMax.isEmpty()) {
            answer[0] = pqMax.peek();
            answer[1] = pqMin.peek();

        }
        return answer;
	}
	public static void main(String[] args) {
		String[] operations = {"I 16", "D 1"};
		int[] answer = solution(operations);
		for(int i = 0; i < answer.length; i++)
			System.out.print(answer[i]+ " ");
	}
}