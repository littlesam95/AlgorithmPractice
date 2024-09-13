import java.util.*;

class Solution {
    
    private static class Position {
		
		int Y, X, D;

		public Position(int y, int x, int d) {
			super();
			Y = y;
			X = x;
			D = d;
		}

		@Override
		public String toString() {
			return "Position [Y=" + Y + ", X=" + X + ", D=" + D + "]";
		}
		
	}
	
	private static int N;
	private static int[][] map = new int[26][26];
	private static int[][][] dp = new int[26][26][4];
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,1,0,-1 };
	private static int Answer = (int) 1e9;
	private static StringBuilder sb = new StringBuilder();
	
	private static void init(int[][] board) {
        N = board.length;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 4; k++) {
					dp[i][j][k] = (int) 1e9;
				}
			}
		}
	}
	
	private static void bfs(int[][] board) {
		Queue<Position> queue = new LinkedList<>();
		queue.add(new Position(0, 0, 1));
		queue.add(new Position(0, 0, 2));
		dp[0][0][1] = 0;
		dp[0][0][2] = 0;
		
		while (!queue.isEmpty()) {
			Position now = queue.poll();
			int nowY = now.Y;
			int nowX = now.X;
			int nowD = now.D;
			
			for (int i = 0; i < 4; i++) {
				int nextY = nowY + moveY[i];
				int nextX = nowX + moveX[i];
				if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) continue;
				if (board[nextY][nextX] == 1) continue;
				if (nowD % 2 == 0) {
					if (i % 2 == 0) {
						if (dp[nextY][nextX][i] > dp[nowY][nowX][nowD] + 100) {
							dp[nextY][nextX][i] = dp[nowY][nowX][nowD] + 100;
							queue.add(new Position(nextY, nextX, i));
						}
					} else {
						if (dp[nextY][nextX][i] > dp[nowY][nowX][nowD] + 600) {
							dp[nextY][nextX][i] = dp[nowY][nowX][nowD] + 600;
							queue.add(new Position(nextY, nextX, i));
						}
					}
				} else {
					if (i % 2 == 0) {
						if (dp[nextY][nextX][i] > dp[nowY][nowX][nowD] + 600) {
							dp[nextY][nextX][i] = dp[nowY][nowX][nowD] + 600;
							queue.add(new Position(nextY, nextX, i));
						}
					} else {
						if (dp[nextY][nextX][i] > dp[nowY][nowX][nowD] + 100) {
							dp[nextY][nextX][i] = dp[nowY][nowX][nowD] + 100;
							queue.add(new Position(nextY, nextX, i));
						}
					}
				}
			}
		}
	}
    
    public int solution(int[][] board) {
        init(board);
		bfs(board);
        for (int i = 0; i < 4; i++) {
			Answer = Math.min(Answer, dp[N - 1][N - 1][i]);
		}
        
        return Answer;
    }
    
}