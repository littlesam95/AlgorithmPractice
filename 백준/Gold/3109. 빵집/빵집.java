import java.io.*;
import java.util.*;

public class Main {
	
	private static int R, C;
	private static int[][] map = new int[10001][501];
	private static boolean[][] visited = new boolean[10001][501];
	private static boolean flag;
	private static int[] moveY = { -1,0,1 };
    private static int Answer = 0;
    
    private static void dfs(int start, int Depth) {
    	if (Depth == C) {
    		Answer++;
    		flag = true;
    		return;
    	}
    	
    	visited[start][Depth] = true;
    	
    	// 1. 오른쪽 위 대각선
    	int next = start + moveY[0];
    	if (!flag && (next >= 0) && (next < R) && !visited[next][Depth + 1] && (map[next][Depth + 1] == 0)) {
    		dfs(next, Depth + 1);
    	}
    	
    	// 2. 오른쪽
    	next = start + moveY[1];
    	if (!flag && (next >= 0) && (next < R) && !visited[next][Depth + 1] && (map[next][Depth + 1] == 0)) {
    		dfs(next, Depth + 1);
    	}
    	
    	// 3. 오른쪽 아래 대각선
    	next = start + moveY[2];
    	if (!flag && (next >= 0) && (next < R) && !visited[next][Depth + 1] && (map[next][Depth + 1] == 0)) {
    		dfs(next, Depth + 1);
    	}
    }
	
	private static void settings() {
		for (int i = 0; i < R; i++) {
			flag = false;
			dfs(i, 0);
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        R = Integer.parseInt(inputs[0]);
        C = Integer.parseInt(inputs[1]);

        for (int i = 0; i < R; i++) {
        	inputs = br.readLine().split("");
        	for (int j = 0; j < C; j++) {
        		if (".".equals(inputs[j])) {
        			map[i][j] = 0;
        		} else {
        			map[i][j] = -1;
        		}
        	}
        }
        settings();
        
        System.out.println(Answer);
        br.close();
    }

}