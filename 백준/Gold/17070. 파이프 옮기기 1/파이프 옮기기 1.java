import java.io.*;
import java.util.*;

public class Main {
	
	private static int N;
	private static int[][] map = new int[17][17];
	private static int[][] dp = new int[17][17];
	private static int[][] moveY = {
			{ 0,-1,1 },
			{ -1,1,1 },
			{ 0,1,1 }
	};
	private static int[][] moveX = {
			{ 1,-1,1 },
			{ -1,0,1 },
			{ 1,0,1 }
	};
	private static int Answer;
	private static StringBuilder sb = new StringBuilder();
	
	private static void dfs(int Y, int X, int Mode) {
		if ((Y == N) && (X == N)) {
			Answer++;
			return;
		}
		
		// System.out.println("(" + Y + ", " + X + ")");
		
		for (int i = 0; i < 3; i++) {
			if ((moveY[Mode][i] == -1) && (moveX[Mode][i] == -1)) continue;
			int nextY = Y + moveY[Mode][i];
			int nextX = X + moveX[Mode][i];
			if ((nextY < 1) || (nextY > N) || (nextX < 1) || (nextX > N)) continue;
			if (i == 2) {
				if ((map[Y + 1][X] != 0) || (map[Y][X + 1] != 0) || (map[nextY][nextX] != 0)) continue;
			} else {
				if (map[nextY][nextX] != 0) continue;
			}
			dfs(nextY, nextX, i);
		}
	}
	
	private static void settings() {
		dfs(1, 2, 0);
		sb.append(Answer + "\n");
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
        	String[] inputs = br.readLine().split(" ");
        	for (int j = 1; j <= N; j++) {
        		map[i][j] = Integer.parseInt(inputs[j - 1]);
        	}
        }
        
        settings();
        
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

}