import java.io.*;
import java.util.*;

public class Main {
	
	private static class Position {
		
		int Y, X;

		public Position(int y, int x) {
			super();
			Y = y;
			X = x;
		}
		
	}
	
	private static int N;
	private static char[][] map = new char[101][101];
	private static boolean[][] visited = new boolean[101][101];
	private static Queue<Position> queue = new LinkedList<>();
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	private static int AnswerA = 0, AnswerB = 0;
    
    private static void bfs(int Y, int X) {
    	queue.add(new Position(Y, X));
    	visited[Y][X] = true;
    	char Color = map[Y][X];
    	
    	while (!queue.isEmpty()) {
    		Position now = queue.poll();
    		int nowY = now.Y;
    		int nowX = now.X;
    		
    		for (int i = 0; i < 4; i++) {
    			int nextY = nowY + moveY[i];
    			int nextX = nowX + moveX[i];
    			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && !visited[nextY][nextX] && (map[nextY][nextX] == Color)) {
					visited[nextY][nextX] = true;
					queue.add(new Position(nextY, nextX));
    			}
    		}
    	}
    }
    
    private static void bfs2(int Y, int X) {
    	queue.add(new Position(Y, X));
    	visited[Y][X] = true;
    	char Color = map[Y][X];
    	
    	while (!queue.isEmpty()) {
    		Position now = queue.poll();
    		int nowY = now.Y;
    		int nowX = now.X;
    		
    		for (int i = 0; i < 4; i++) {
    			int nextY = nowY + moveY[i];
    			int nextX = nowX + moveX[i];
    			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && !visited[nextY][nextX]) {
    				if ((Color == 'R') || (Color == 'G')) {
    					if (map[nextY][nextX] != 'B') {
    						visited[nextY][nextX] = true;
    						queue.add(new Position(nextY, nextX));
    					}
    				} else {
    					if (map[nextY][nextX] == 'B') {
    						visited[nextY][nextX] = true;
    						queue.add(new Position(nextY, nextX));
    					}
    				}
    			}
    		}
    	}
    }
	
	private static void settings() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
					AnswerA++;
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs2(i, j);
					AnswerB++;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
        	String input = br.readLine();
        	for (int j = 0; j < N; j++) {
        		map[i][j] = input.charAt(j);
        	}
        }
        settings();
        
        System.out.println(AnswerA + " " + AnswerB);
        br.close();
    }

}