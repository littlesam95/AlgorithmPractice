import java.io.*;
import java.util.*;

public class Main {
	
	private static class Position {
		
		int Y, X, K, C;

		public Position(int y, int x, int k, int c) {
			super();
			Y = y;
			X = x;
			K = k;
			C = c;
		}

		@Override
		public String toString() {
			return "Position [Y=" + Y + ", X=" + X + ", K=" + K + ", C=" + C + "]";
		}
		
	}
	
	private static int W, H, K;
	private static int[][] map = new int[201][201];
	private static boolean[][][] visited = new boolean[201][201][31];
	private static Queue<Position> queue = new LinkedList<>();
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	private static int[] horseY = { -1,-2,-2,-1,1,2,2,1 };
	private static int[] horseX = { -2,-1,1,2,2,1,-1,-2 };
	private static int Answer = Integer.MAX_VALUE;
    
    private static int bfs() {
    	queue.add(new Position(0, 0, K, 0));
    	visited[0][0][K] = true;
    	
    	while (!queue.isEmpty()) {
    		Position now = queue.poll();
    		int nowY = now.Y;
    		int nowX = now.X;
    		int nowK = now.K;
    		int nowC = now.C;
    		
    		if ((nowY == H - 1) && (nowX == W - 1)) {
    			return nowC;
    		}
    		
    		if (nowK > 0) {
    			for (int i = 0; i < 8; i++) {
        			int nextY = nowY + horseY[i];
        			int nextX = nowX + horseX[i];
        			if ((nextY >= 0) && (nextY < H) && (nextX >= 0) && (nextX < W) && !visited[nextY][nextX][nowK - 1] && (map[nextY][nextX] == 0)) {
            			visited[nextY][nextX][nowK - 1] = true;
            			queue.add(new Position(nextY, nextX, nowK - 1, nowC + 1));
        			}
        		}
    		}
    		for (int i = 0; i < 4; i++) {
    			int nextY = nowY + moveY[i];
    			int nextX = nowX + moveX[i];
    			if ((nextY >= 0) && (nextY < H) && (nextX >= 0) && (nextX < W) && !visited[nextY][nextX][nowK] && (map[nextY][nextX] == 0)) {
    				visited[nextY][nextX][nowK] = true;
        			queue.add(new Position(nextY, nextX, nowK, nowC + 1));
    			}
    		}
    	}
    	
    	return -1;
    }
	
	private static void settings() {
		Answer = bfs();
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        K = Integer.parseInt(br.readLine());
        String[] inputs = br.readLine().split(" ");
        W = Integer.parseInt(inputs[0]);
        H = Integer.parseInt(inputs[1]);

        for (int i = 0; i < H; i++) {
        	String[] input = br.readLine().split(" ");
        	for (int j = 0; j < W; j++) {
        		map[i][j] = Integer.parseInt(input[j]);
        	}
        }
        settings();
        
        System.out.println(Answer);
        br.close();
    }

}