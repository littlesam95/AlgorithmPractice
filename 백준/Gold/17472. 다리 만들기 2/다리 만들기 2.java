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

		@Override
		public String toString() {
			return "Position [Y=" + Y + ", X=" + X + "]";
		}
		
	}
	
	private static class EdgeInfo implements Comparable<EdgeInfo> {
		
		int From, To, Cost;

		public EdgeInfo(int from, int to, int cost) {
			super();
			From = from;
			To = to;
			Cost = cost;
		}

		@Override
		public String toString() {
			return "EdgeInfo [From=" + From + ", To=" + To + ", Cost=" + Cost + "]";
		}
		
		@Override
		public int compareTo(EdgeInfo o) {
			return this.Cost - o.Cost;
		}
		
	}
	
	private static int N, M, islandCount;
	private static int[][] map = new int[11][11];
	private static int[][] islands = new int[11][11];
	private static int[] parents = new int[7];
	private static Queue<Position> queue = new LinkedList<>();
	private static List<EdgeInfo> edges = new ArrayList<>();
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,-1,0,1 };
	private static int Answer = 0;
	
	private static void init() {
		for (int i = 0; i < 7; i++) {
			parents[i] = i;
		}
	}
    
    private static void bfs(int Y, int X, int I) {
    	queue.add(new Position(Y, X));
    	islands[Y][X] = I;
    	
    	while (!queue.isEmpty()) {
    		Position now = queue.poll();
    		int nowY = now.Y;
    		int nowX = now.X;
    		
    		for (int i = 0; i < 4; i++) {
    			int nextY = nowY + moveY[i];
    			int nextX = nowX + moveX[i];
    			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (islands[nextY][nextX] == 0) && (map[nextY][nextX] == 1)) {
        			islands[nextY][nextX] = I;
        			queue.add(new Position(nextY, nextX));
    			}
    		}
    	}
    }
    
    private static int findParent(int X) {
    	if (parents[X] == X) {
    		return X;
    	}
    	
    	return parents[X] = findParent(parents[X]);
    }
    
    private static void unionGroup(int X, int Y) {
    	int ParentX = findParent(X);
    	int ParentY = findParent(Y);
    	
    	if (ParentX < ParentY) {
    		parents[ParentY] = ParentX;
    	} else {
    		parents[ParentX] = ParentY;
    	}
    }
	
	private static void settings() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((islands[i][j] == 0) && (map[i][j] == 1)) {
					bfs(i, j, islandCount + 1);
					islandCount++;
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (islands[i][j] > 0) {
					int islandIndex = islands[i][j];
					for (int k = 0; k < 4; k++) {
						int nextY = i;
						int nextX = j;
						while (true) {
							nextY += moveY[k];
							nextX += moveX[k];
							if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M)) {
								break;
							}
							if ((islands[nextY][nextX] != 0) && (islands[nextY][nextX] == islandIndex)) {
								break;
							}
							if ((islands[nextY][nextX] != 0) && (islands[nextY][nextX] != islandIndex)) {
								int Length = Math.abs(i - nextY) + Math.abs(j - nextX) - 1;
								edges.add(new EdgeInfo(islandIndex, islands[nextY][nextX], Length));
								break;
							}
						}
					}
				}
			}
		}
		
		Collections.sort(edges);
		
		for (int i = 0; i < edges.size(); i++) {
			int From = edges.get(i).From;
			int To = edges.get(i).To;
			int Cost = edges.get(i).Cost;
			if (Cost < 2) continue;
			if (findParent(From) != findParent(To)) {
				unionGroup(From, To);
				Answer += Cost;
			}
		}
		
		for (int i = 1; i <= islandCount; i++) {
			if (findParent(i) != 1) {
				Answer = -1;
				break;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        init();

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        for (int i = 0; i < N; i++) {
        	inputs = br.readLine().split(" ");
        	for (int j = 0; j < M; j++) {
        		map[i][j] = Integer.parseInt(inputs[j]);
        	}
        }
        settings();
        
        System.out.println(Answer);
        br.close();
    }

}