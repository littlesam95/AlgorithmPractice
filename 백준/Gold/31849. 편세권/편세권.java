import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] MAP = new int[1001][1001];
	static int[] MoveY = { -1,0,1,0 };
	static int[] MoveX = { 0,-1,0,1 };
	static int Answer = 1000000000;
	
	public static class Convenience {
		int c, d;
		
		public Convenience(int c, int d) {
			this.c = c;
			this.d = d;
		}
	}
	
	public static class ConvenienceInfo {
		int y, x, t;
		
		public ConvenienceInfo(int y, int x, int t) {
			this.y = y;
			this.x = x;
			this.t = t;
		}
	}
	
	public static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void settings(int N, int M, int C, Convenience[] convenience) {
		boolean[][] Visited = new boolean[1001][1001];
		Queue<ConvenienceInfo> que = new LinkedList<ConvenienceInfo>();
		for (int i = 0; i < C; i++) {
			int c = convenience[i].c;
			int d = convenience[i].d;
			que.add(new ConvenienceInfo(c, d, 0));
			Visited[c][d] = true; 
		}
		
		while (!que.isEmpty()) {
			ConvenienceInfo nowConvenienceInfo = que.poll();
			int NowY = nowConvenienceInfo.y;
			int NowX = nowConvenienceInfo.x;
			int NowT = nowConvenienceInfo.t;
			
			if (MAP[NowY][NowX] > 0) {
				Answer = Math.min(Answer, MAP[NowY][NowX] * NowT);
			}
			
			for (int i = 0; i < 4; i++) {
				int NextY = NowY + MoveY[i];
				int NextX = NowX + MoveX[i];
				if ((NextY > 0) && (NextY <= N) && (NextX > 0) && (NextX <= M) && !Visited[NextY][NextX]) {
					que.add(new ConvenienceInfo(NextY, NextX, NowT + 1));
					Visited[NextY][NextX] = true; 
				}
			}
		};
		
		
		find_Answer();
	}
	
	public static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);
		int R = Integer.parseInt(input[2]);
		int C = Integer.parseInt(input[3]);
		for (int i = 0; i < R; i++) {
			String[] A = br.readLine().split(" ");
			int a = Integer.parseInt(A[0]);
			int b = Integer.parseInt(A[1]);
			int p = Integer.parseInt(A[2]);
			MAP[a][b] = p; 
		}
		Convenience[] convenience = new Convenience[C];
		for (int i = 0; i < C; i++) {
			String[] A = br.readLine().split(" ");
			int c = Integer.parseInt(A[0]);
			int d = Integer.parseInt(A[1]);
			convenience[i] = new Convenience(c, d); 
		}
		settings(N, M, C, convenience);
	}

	public static void main(String[] args) throws IOException {
		input();
	}

}