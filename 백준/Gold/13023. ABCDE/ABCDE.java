import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, M;
	private static ArrayList<Integer>[] edges = new ArrayList[2001];
	private static int[] visited = new int[2001];
	private static int Answer;
	
	private static void dfs(int now, int Depth) {
		visited[now] = Depth;
		if (Depth == 5) {
			Answer = 1;
			return;
		}
		
		for (int i = 0; i < edges[now].size(); i++) {
			int next = edges[now].get(i);
			if (visited[next] == 0) {
				dfs(next, Depth + 1);
			}
		}
		visited[now] = 0;
	}
	
	private static void settings() {
		for (int i = 0; i < N; i++) {
			dfs(i, 1);
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        for (int i = 0; i < N; i++) {
        	edges[i] = new ArrayList<Integer>();
        }
        M = Integer.parseInt(inputs[1]);
        
        for (int i = 0; i < M; i++) {
        	inputs = br.readLine().split(" ");
        	int A = Integer.parseInt(inputs[0]);
        	int B = Integer.parseInt(inputs[1]);
        	edges[A].add(B);
        	edges[B].add(A);
        }
        
        settings();
        
        System.out.println(Answer);
    }

}