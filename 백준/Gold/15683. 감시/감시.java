import java.io.*;
import java.util.*;

public class Main {
	
	static class Position {
		int T, Y, X;
		
		public Position(int T, int Y, int X) {
			this.T = T;
			this.Y = Y;
			this.X = X;
		}
	}
	
	private static int N;
	private static int M;
	private static ArrayList<Position> cctvs = new ArrayList<>();
	private static int[][] map = new int[9][9];
	private static int[][] visited = new int[9][9];
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	private static int Answer = 65;
	
	public static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void settings(int Depth) {
		if (Depth == cctvs.size()) {
			int nowSum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((map[i][j] == 0) && (visited[i][j] == 0)) {
						nowSum++;
					}
				}
			}
			Answer = Math.min(Answer, nowSum);
			return;
		}
		
		int T = cctvs.get(Depth).T;
		int Y = cctvs.get(Depth).Y;
		int X = cctvs.get(Depth).X;
		
		if (T == 1) {
			for (int i = 0; i < 4; i++) {
				// 감시
				int nextY = Y;
				int nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[i];
					nextX += moveX[i];
				};
				
				settings(Depth + 1);
				
				// 원복
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[i];
					nextX += moveX[i];
				};
			}
		} else if (T == 2) {
			for (int i = 0; i < 2; i++) {
				// 감시
				int nextY = Y;
				int nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[i];
					nextX += moveX[i];
				};
				
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[i + 2];
					nextX += moveX[i + 2];
				};
				
				settings(Depth + 1);
				
				// 원복
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[i];
					nextX += moveX[i];
				};
				
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[i + 2];
					nextX += moveX[i + 2];
				};
			}
		} else if (T == 3) {
			for (int i = 0; i < 4; i++) {
				// 감시
				int nextY = Y;
				int nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[i];
					nextX += moveX[i];
				};
				
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[(i + 1) % 4];
					nextX += moveX[(i + 1) % 4];
				};
				
				settings(Depth + 1);
				
				// 원복
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[i];
					nextX += moveX[i];
				};
				
				nextY = Y;
				nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[(i + 1) % 4];
					nextX += moveX[(i + 1) % 4];
				};
			}
		} else if (T == 4) {
			for (int i = 0; i < 4; i++) {
				// 감시
				for (int j = 0; j < 4; j++) {
					if (i == j) continue;
					int nextY = Y;
					int nextX = X;
					while (true) {
						if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
							break;
						}
						if (map[nextY][nextX] == 6) {
							break;
						}
						
						visited[nextY][nextX]++;
						nextY += moveY[j];
						nextX += moveX[j];
					};
				}
				
				settings(Depth + 1);
				
				// 원복
				for (int j = 0; j < 4; j++) {
					if (i == j) continue;
					int nextY = Y;
					int nextX = X;
					while (true) {
						if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
							break;
						}
						if (map[nextY][nextX] == 6) {
							break;
						}
						
						visited[nextY][nextX]--;
						nextY += moveY[j];
						nextX += moveX[j];
					};
				}
			}
		} else if (T == 5) {
			for (int i = 0; i < 4; i++) {
				int nextY = Y;
				int nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]++;
					nextY += moveY[i];
					nextX += moveX[i];
				};
			}
			
			settings(Depth + 1);

			// 원복
			for (int i = 0; i < 4; i++) {
				int nextY = Y;
				int nextX = X;
				while (true) {
					if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
						break;
					}
					if (map[nextY][nextX] == 6) {
						break;
					}
					
					visited[nextY][nextX]--;
					nextY += moveY[i];
					nextX += moveX[i];
				};
			}
		}
	}
	
	public static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        for (int i = 0; i < N; i++) {
        	inputs = br.readLine().split(" ");
        	for (int j = 0; j < M; j++) {
        		map[i][j] = Integer.parseInt(inputs[j]);
        		if ((map[i][j] >= 1) && (map[i][j] <= 5)) {
        			cctvs.add(new Position(map[i][j], i, j));
        		}
        	}
        }
	}

	public static void main(String[] args) throws IOException {
		input();
        settings(0);
        find_Answer();
	}
}