// 프로그래머스 고득점 kit 스택/큐 - 기능개발
import java.util.*;

public class practice2 {
	public static int[] solution(int[] progresses, int[] speeds) {
        var listPro = new ArrayList<Integer>();
        var listSpe = new ArrayList<Integer>();
        var listAns = new ArrayList<Integer>();
        
        for(int i = 0; i < progresses.length; i++) {
        	listPro.add(progresses[i]);
        	listSpe.add(speeds[i]);
        }
        
        while(!listPro.isEmpty()) {
        	int count = 0;
        	while(listPro.get(0) < 100) {
        		for(int i = 0; i < listPro.size(); i++)
        			listPro.set(i, listPro.get(i) + listSpe.get(i));
        	}
        	for(int i = 0; i < listPro.size(); i++) {
        		if(listPro.get(i) >= 100)
        			count++;
        		else break;
        	}
        	listAns.add(count);
        	
        	while(count-- > 0) {
        		listPro.remove(0);
        		listSpe.remove(0);
        	}
        }
		int[] answer = new int[listAns.size()];
		for(int i = 0; i < listAns.size(); i++)
			answer[i] = listAns.get(i);
        
        return answer;
    }
	
	public static void main(String[] args) {
		int[] progresses = {93, 30, 55};
		int[] speeds = {1, 30, 5};
		int[] answer = solution(progresses, speeds);
		
		for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
		}
	}
}
