import java.io.*;
import java.util.*;

public class Main {
	
	private static class Node {
		public int vertex;
		public Node link;
		public int weight;
		
		public Node(int vertex, Node link, int weight) {
			super();
			this.vertex = vertex;
			this.link = link;
			this.weight = weight;
		}

		@Override
		public String toString() {
			return "Node [vertex=" + vertex + ", link=" + link + ", weight=" + weight + "]";
		}
	}
	
	private static final int INF = Integer.MAX_VALUE;
	
	private static int N;
	private static int Problem;
	private static int[][] map = new int[126][126];
	private static Node[] adjList = new Node[126 * 126];
	private static int[] Dist = new int[126 * 126];
	private static boolean[] visited = new boolean[126 * 126];
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	
	private static void init() {
		for (int i = 0; i < (126 * 126); i++) {
			Dist[i] = INF;
			visited[i] = false;
		}
		adjList = new Node[126 * 126];
	}
	
	private static void settings() {
		Dist[0] = 0;
		
		int min = 0;
		int current = 0;
		
		for (int cnt = 0; cnt < (N * N); cnt++) {
			current = -1;
			min = INF;
			for (int i = 0; i < (N * N); i++) {
				if (!visited[i] && (Dist[i] < min)) {
					min = Dist[i];
					current = i;
				}
			}
			
			if (current == -1) break;
			
			visited[current] = true;
			
			for (Node temp = adjList[current]; temp != null; temp = temp.link) {
				if (!visited[temp.vertex] && (Dist[temp.vertex] > min + temp.weight)) {
					Dist[temp.vertex] = min + temp.weight;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            init();
            N = Integer.parseInt(br.readLine());
            if (N == 0) break;
            for (int i = 0; i < N; i++) {
            	String[] inputs = br.readLine().split(" ");
            	for (int j = 0; j < N; j++) {
            		map[i][j] = Integer.parseInt(inputs[j]);
            	}
            }
            for (int i = 0; i < N; i++) {
            	for (int j = 0; j < N; j++) {
            		int From = (i * N) + j;
            		for (int k = 0; k < 4; k++) {
            			int nextY = i + moveY[k];
            			int nextX = j + moveX[k];
            			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) continue;
            			int To = (nextY * N) + nextX;
            			int Cost = map[i][j];
            			adjList[From] = new Node(To, adjList[From], Cost);
            		}
            	}
            }
            
            settings();
            
            System.out.println("Problem " + (++Problem) + ": " + (Dist[(N * N) - 1] + map[N - 1][N - 1]));
        }
    }

}