import java.io.*;
import java.util.*;

public class Main {
	
	private static class Info {
		int To, Cost;
		
		public Info(int To, int Cost) {
			this.To = To;
			this.Cost = Cost;
		}
	}
	
	private static class Info2 implements Comparable<Info2> {
		int Cost, X;
		
		public Info2(int Cost, int X) {
			this.Cost = Cost;
			this.X = X;
		}

		@Override
		public int compareTo(Info2 o) {
			if (this.Cost == o.Cost) {
				return (this.X - o.X);
			}
			
			return (this.Cost - o.Cost);
		}
	}
	
	private static int V, E, K;
	private static ArrayList<ArrayList<Info>> edges = new ArrayList<>();
	private static int[] Dist = new int[20001];
	
	private static void init(int V) {
		for (int i = 0; i <= V; i++) {
			Dist[i] = Integer.MAX_VALUE;
			edges.add(new ArrayList<Info>());
		}
	}
	
	private static void settings() {
		Queue<Info2> queue = new PriorityQueue<Info2>();
		queue.add(new Info2(0, K));
		Dist[K] = 0;
		
		while (!queue.isEmpty()) {
			Info2 now = queue.poll();
			int nowC = now.Cost;
			int nowX = now.X;
			
			if (Dist[nowX] < nowC) continue;
			
			for (int i = 0; i < edges.get(nowX).size(); i++) {
				int nextX = edges.get(nowX).get(i).To;
				int nextC = edges.get(nowX).get(i).Cost;
				if (Dist[nextX] > Dist[nowX] + nextC) {
					Dist[nextX] = Dist[nowX] + nextC;
					queue.add(new Info2(Dist[nextX], nextX));
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputs = br.readLine().split(" ");
        V = Integer.parseInt(inputs[0]);
        init(V);
        E = Integer.parseInt(inputs[1]);
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < E; i++) {
        	inputs = br.readLine().split(" ");
        	int From = Integer.parseInt(inputs[0]);
        	int To = Integer.parseInt(inputs[1]);
        	int Cost = Integer.parseInt(inputs[2]);
        	edges.get(From).add(new Info(To, Cost));
        }
        
        settings();
        
        StringBuilder Answer = new StringBuilder();
        for (int i = 1; i <= V; i++) {
        	if (Dist[i] == Integer.MAX_VALUE) {
        		Answer.append("INF");
        	} else {
        		Answer.append(Dist[i]);
        	}
        	Answer.append("\n");
        }
        
        bw.write(Answer.toString());
        br.close();
        bw.close();
    }

}