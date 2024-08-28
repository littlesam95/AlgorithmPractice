import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, M, V;
	private static ArrayList<Integer>[] edges = new ArrayList[1001];
	private static boolean[] visited = new boolean[1001];
	private static ArrayList<Integer> dfsResult = new ArrayList<>();
	private static ArrayList<Integer> bfsResult = new ArrayList<>();
	
	private static void init() {
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
	}
	
	private static void dfs(int now) {
		visited[now] = true;
		dfsResult.add(now);
		
		for (int i = 0; i < edges[now].size(); i++) {
			int next = edges[now].get(i);
			if (!visited[next]) {
				dfs(next);
			}
		}
	}
	
	private static void bfs() {
		Queue<Integer> queue = new LinkedList<>();
		visited[V] = true;
		queue.add(V);
		
		while (!queue.isEmpty()) {
			int nowX = queue.poll();
			
			bfsResult.add(nowX);
			
			for (int i = 0; i < edges[nowX].size(); i++) {
				int nextX = edges[nowX].get(i);
				if (!visited[nextX]) {
					visited[nextX] = true;
					queue.add(nextX);
				}
			}
		}
	}
	
	private static void settings() {
        for (int i = 1; i <= N; i++) {
        	Collections.sort(edges[i]);
        }
        
		init();
		dfs(V);
		init();
		bfs();
	}
	
	private static void find_Answer() {
		for (int i = 0; i < dfsResult.size(); i++) {
			System.out.print(dfsResult.get(i) + " ");
		}
		System.out.println();
		for (int i = 0; i < bfsResult.size(); i++) {
			System.out.print(bfsResult.get(i) + " ");
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        V = Integer.parseInt(inputs[2]);
        
        for (int i = 1; i <= N; i++) {
        	edges[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < M; i++) {
        	inputs = br.readLine().split(" ");
        	int From = Integer.parseInt(inputs[0]);
        	int To = Integer.parseInt(inputs[1]);
        	edges[From].add(To);
        	edges[To].add(From);
        }
		
		settings();
		find_Answer();
	}

}