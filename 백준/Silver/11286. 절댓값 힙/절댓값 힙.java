import java.io.*;
import java.util.*;

public class Main {
	
	private static int N;
	private static Queue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {

		@Override
		public int compare(Integer o1, Integer o2) {
			if (Math.abs(o1) == Math.abs(o2)) {
				return (o1 - o2);
			}
			
			return (Math.abs(o1) - Math.abs(o2));
		}
	});
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < N; i++) {
        	int X = Integer.parseInt(br.readLine());
        	if (X == 0) {
        		if (queue.isEmpty()) {
        			System.out.println(0);
        		} else {
            		System.out.println(queue.poll());
        		}
        	} else {
            	queue.offer(X);
        	}
        }
    }
}