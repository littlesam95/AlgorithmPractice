import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, M;
	private static List<Integer> snacks = new ArrayList<Integer>();
    private static int Answer = 0;
    
    private static boolean checkLength(int length) {
    	int person = 0;
    	for (int i = (N - 1); i >= 0; i--) {
    		if ((snacks.get(i) / length) == 0) break;
    		if (person >= M) {
        		return true;
        	}
    		person += (snacks.get(i) / length);
    	}
    	
    	if (person >= M) {
    		return true;
    	}
    	
    	return false;
    }
	
	private static void settings() {
		int left = 1;
		int right = snacks.get(snacks.size() - 1);
		
		while (left <= right) {
			int mid = (left + right) / 2;
			
			if (checkLength(mid)) {
				Answer = Math.max(Answer, mid);
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        M = Integer.parseInt(inputs[0]);
        N = Integer.parseInt(inputs[1]);

    	inputs = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
        	snacks.add(Integer.parseInt(inputs[i]));
        }
        Collections.sort(snacks);
        settings();
        
        System.out.println(Answer);
        br.close();
    }

}