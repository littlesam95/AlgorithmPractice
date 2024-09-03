import java.io.*;
import java.util.*;

public class Main {
	
	private static class Medal implements Comparable<Medal> {
		
		String title;
		int Power;
		
		public Medal(String title, int power) {
			super();
			this.title = title;
			Power = power;
		}
		
		@Override
		public String toString() {
			return "Medal [title=" + title + ", Power=" + Power + "]";
		}

		@Override
		public int compareTo(Medal o) {
			return this.Power - o.Power;
		}
		
	}
	
	private static int N, M;
	private static List<Medal> medals = new ArrayList<Medal>();
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        
        for (int i = 0; i < N; i++) {
        	inputs = br.readLine().split(" ");
        	medals.add(new Medal(inputs[0], Integer.parseInt(inputs[1])));
        }
        Collections.sort(medals);
        
        for (int j = 0; j < M; j++) {
        	int P = Integer.parseInt(br.readLine());
        	
        	// lower_bound 구현
        	int left = 0;
        	int right = medals.size();
        	
        	while (left < right) {
        		int mid = (left + right) / 2;
        		
        		if (P > medals.get(mid).Power) {
        			left = mid + 1;
        		} else {
        			right = mid;
        		}
        	}
        	
        	sb.append(medals.get(right).title + "\n");
        }
        
        System.out.println(sb.toString());
        br.close();
    }

}