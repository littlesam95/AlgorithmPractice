import java.io.*;
import java.util.*;

public class Main {
	
	private static class Info {
		int X;
		boolean flag;
		
		public Info(int X, boolean flag) {
			this.X = X;
			this.flag = flag;
		}
	}
	
	private static int N;
	private static int[] people = new int[11];
	private static int allPeople;
	private static ArrayList<Integer>[] edges = new ArrayList[11];
	private static boolean[] visited = new boolean[11];
	private static boolean[] tempVisited = new boolean[11];
	private static int Answer = 1000000000;
	
	private static boolean bfs(int R, int B) {
		Queue<Info> queue = new LinkedList<>();
		tempVisited[R] = true;
		tempVisited[B] = true;
		int RedCount = 1;
		int BlueCount = 1;
		queue.add(new Info(R, true));
		queue.add(new Info(B, false));
		
		while (!queue.isEmpty()) {
			Info now = queue.poll();
			int nowX = now.X;
			boolean nowF = now.flag;
			
			for (int i = 0; i < edges[nowX].size(); i++) {
				int next = edges[nowX].get(i);
				if ((visited[next] == nowF) && !tempVisited[next]) {
					tempVisited[next] = true;
					queue.add(new Info(next, nowF));
					if (nowF) {
						RedCount++;
					} else {
						BlueCount++;
					}
				}
			}
		}
		
		if (RedCount + BlueCount == N) {
			return true;
		}
		
		return false;
	}
	
	private static boolean check() {
		for (int i = 0; i < 11; i++) {
			tempVisited[i] = false;
		}
		int R = -1;
		int B = -1;
		for (int i = 1; i <= N; i++) {
			if (visited[i] && (R == -1)) {
				R = i;
			}
			if (!visited[i] && (B == -1)) {
				B = i;
			}
		}
		
		return bfs(R, B);
	}
	
	private static void dfs(int Start, int Depth, int Red, int Blue) {
		if ((Depth > 0) && check()) {
			Answer = Math.min(Answer, Math.abs(Red - Blue));
		}
		if (Depth >= N - 1) {
			return;
		}
		
		for (int i = Start; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i + 1, Depth + 1, Red + people[i], Blue - people[i]);
				visited[i] = false;
			}
		}
	}
	
	private static void settings() {
		dfs(1, 0, 0, allPeople);
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        String[] inputs = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
        	people[i] = Integer.parseInt(inputs[i - 1]);
        	allPeople += people[i];
        }
        for (int i = 1; i <= N; i++) {
        	edges[i] = new ArrayList<Integer>();
        	inputs = br.readLine().split(" ");
        	int Count = Integer.parseInt(inputs[0]);
        	for (int j = 0; j < Count; j++) {
        		edges[i].add(Integer.parseInt(inputs[j + 1]));
        	}
        }
        
        settings();
        
        if (Answer == 1000000000) {
        	System.out.println(-1);
        } else {
            System.out.println(Answer);
        }
    }

}