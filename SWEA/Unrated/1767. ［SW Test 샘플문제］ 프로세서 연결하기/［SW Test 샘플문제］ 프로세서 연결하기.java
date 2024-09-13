import java.io.*;
import java.util.*;

public class Solution {
	
	private static class Core {
		
		int Y, X;

		public Core(int y, int x) {
			super();
			Y = y;
			X = x;
		}

		@Override
		public String toString() {
			return "Core [Y=" + Y + ", X=" + X + "]";
		}
		
	}
     
    private static int N, maxCore;
    private static int[][] map = new int[13][13];
    private static List<Core> cores;
	private static int[] moveY = { -1,0,1,0 };
	private static int[] moveX = { 0,1,0,-1 };
    private static int Answer;
    private static StringBuilder sb = new StringBuilder();
     
    private static void init() {
    	cores = new ArrayList<Core>();
    	maxCore = 0;
        Answer = (int) 1e9;
    }
    
    private static boolean isConnectable(int Y, int X, int D) {
    	int nowY = Y;
    	int nowX = X;
    	
    	while (true) {
    		nowY += moveY[D];
    		nowX += moveX[D];
    		if (map[nowY][nowX] == 1) return false;
    		if ((nowY == 1) || (nowX == 1) || (nowY == N) || (nowX == N)) return true;
    	}
    }
    
    private static int setLine(int Y, int X, int D, int V) {
    	int nowY = Y;
    	int nowX = X;
    	int Result = 0;
    	
    	while (true) {
    		if ((nowY == 1) || (nowX == 1) || (nowY == N) || (nowX == N)) break;
    		nowY += moveY[D];
    		nowX += moveX[D];
    		map[nowY][nowX] = V;
    		Result++;
    	}
    	
    	return Result;
    }
    
    private static void dfs(int depth, int connected, int lineCount) {
    	if (depth == cores.size()) {
    		if (maxCore < connected) {
    			maxCore = connected;
    			Answer = lineCount;
    		} else if (maxCore == connected) {
    			if (Answer > lineCount) {
    				Answer = lineCount;
    			}
    		}
    		
    		return;
    	}
    	
    	int Y = cores.get(depth).Y;
    	int X = cores.get(depth).X;
    	
    	for (int i = 0; i < 4; i++) {
    		if (isConnectable(Y, X, i)) {
    			// 전선 놓기
    			int nowLineCount = setLine(Y, X, i, 1);
    			dfs(depth + 1, connected + 1, lineCount + nowLineCount);
    			setLine(Y, X, i, 0);
    		}
    	}
    	
    	dfs(depth + 1, connected, lineCount);
    }
 
    private static void settings() {
    	dfs(0, 0, 0);
    }
     
    public static void main(String[] args) throws IOException {
        // System.setIn(new FileInputStream("1767_input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
          
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            init();
             
            sb.append("#" + test_case + " ");
 
            N = Integer.parseInt(br.readLine());
            for (int i = 1; i <= N; i++) {
            	String[] inputs = br.readLine().split(" ");
                for (int j = 1; j <= N; j++) {
                    map[i][j] = Integer.parseInt(inputs[j - 1]);
                    if ((i == 1) || (j == 1) || (i == N) || (j == N)) continue;
                    if (map[i][j] == 1) {
                    	cores.add(new Core(i, j));
                    }
                }
            }
             
            settings();
             
            sb.append(Answer + "\n");
        }
          
        bw.write(sb.toString());
        bw.close();
        br.close();
    }
	
}