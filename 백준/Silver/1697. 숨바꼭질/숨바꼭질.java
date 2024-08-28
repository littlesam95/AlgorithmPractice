import java.io.*;
import java.util.*;

public class Main {
	
	private static class Info {
		int X, D;
		
		public Info(int X, int D) {
			this.X = X;
			this.D = D;
		}
	}
	
	private static int N, K;
	private static boolean[] visited = new boolean[100001];
	private static int Answer = Integer.MAX_VALUE;
	
	private static void settings() {
		Queue<Info> queue = new LinkedList<>();
		visited[N] = true;
		queue.add(new Info(N, 0));
		
		while (!queue.isEmpty()) {
			Info now = queue.poll();
			int nowX = now.X;
			int nowD = now.D;
			
			if (nowX == K) {
				Answer = Math.min(Answer, nowD);
				return;
			}
			
			if ((nowX - 1 >= 0) && !visited[nowX - 1]) {
				visited[nowX - 1] = true;
				queue.add(new Info(nowX - 1, nowD + 1));
			}
			if ((nowX + 1 <= 100000) && !visited[nowX + 1]) {
				visited[nowX + 1] = true;
				queue.add(new Info(nowX + 1, nowD + 1));
			}
			if ((nowX * 2 <= 100000) && !visited[nowX * 2]) {
				visited[nowX * 2] = true;
				queue.add(new Info(nowX * 2, nowD + 1));
			}
		}
	}
	
	private static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);
		
		settings();
		find_Answer();
	}

}