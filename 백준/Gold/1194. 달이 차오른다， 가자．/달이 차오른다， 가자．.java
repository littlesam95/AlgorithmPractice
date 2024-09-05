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
	
	private static int N, M;
	private static Position start;
	private static char[][] map = new char[51][51];
	private static boolean[][][] visited = new boolean[51][51][1 << 6];
	private static Queue<Position> queue = new LinkedList<>();
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	private static int Answer = 0;
    
    private static int bfs() {
    	queue.add(new Position(start.Y, start.X, 0, 0));
    	visited[start.Y][start.X][0] = true;
    	
    	while (!queue.isEmpty()) {
    		Position now = queue.poll();
    		int nowY = now.Y;
    		int nowX = now.X;
    		int nowKey = now.K;
    		int nowCount = now.C;
    		
    		if (map[nowY][nowX] == '1') {
    			return nowCount;
    		}
    		
    		for (int i = 0; i < 4; i++) {
    			int nextY = nowY + moveY[i];
    			int nextX = nowX + moveX[i];
    			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && !visited[nextY][nextX][nowKey] && (map[nextY][nextX] != '#')) {
        			char next = map[nextY][nextX];
    				if ((next >= 'a') && (next <= 'f')) {
    					int nextKey = nowKey | (1 << (next - 'a'));
    					visited[nextY][nextX][nextKey] = true;
    					queue.add(new Position(nextY, nextX, nextKey, nowCount + 1));
    				} else if ((next >= 'A') && (next <= 'F')) {
    					int isGetKey = nowKey & (1 << (next - 'A'));
    					if (isGetKey > 0) {
    						visited[nextY][nextX][nowKey] = true;
    						queue.add(new Position(nextY, nextX, nowKey, nowCount + 1));
    					}
    				} else if ((next == '.') || (next == '0') || (next == '1')) {
						visited[nextY][nextX][nowKey] = true;
						queue.add(new Position(nextY, nextX, nowKey, nowCount + 1));
    				}
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

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        for (int i = 0; i < N; i++) {
        	String input = br.readLine();
        	for (int j = 0; j < M; j++) {
        		map[i][j] = input.charAt(j);
        		if (map[i][j] == '0') {
        			start = new Position(i, j, 0, 0);
        		}
        	}
        }
        settings();
        
        System.out.println(Answer);
        br.close();
    }

}