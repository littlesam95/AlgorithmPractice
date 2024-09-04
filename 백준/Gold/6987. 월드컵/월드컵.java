import java.io.*;
import java.util.*;

public class Main {
	
	private static int Index;
	private static int[][] matches = new int[15][2];
	private static int[] infos = new int[18];
	private static int[] Answers = new int[4];
    
    private static void dfs(int Depth) {
    	if (Depth == 15) { // 6팀의 리그전은 총 15번의 경기를 한다.
			boolean Flag = true;
    		for (int i = 0; i < 18; i++) {
    			if (infos[i] != 0) {
    				Flag = false;
    			}
    		}
    		
    		if (Flag) {
    			Answers[Index] = 1;
    		}
            
    		return;
    	}
    	
    	int i = matches[Depth][0];
    	int j = matches[Depth][1];
    	int iWin = infos[(i * 3)];
		int iDraw = infos[(i * 3) + 1];
		int iLoss = infos[(i * 3) + 2];
		int jWin = infos[(j * 3)];
		int jDraw = infos[(j * 3) + 1];
		int jLoss = infos[(j * 3) + 2];

		// 1. i가 이기면
		if ((iWin > 0) && (jLoss > 0)) {
			infos[(i * 3)]--;
			infos[(j * 3) + 2]--;
			dfs(Depth + 1);
			infos[(j * 3) + 2]++;
			infos[(i * 3)]++;
		}
		
		// 2. j가 이기면
		if ((iLoss > 0) && (jWin > 0)) {
			infos[(j * 3)]--;
			infos[(i * 3) + 2]--;
			dfs(Depth + 1);
			infos[(i * 3) + 2]++;
			infos[(j * 3)]++;
		}
		
		// 3. 비기면
		if ((iDraw > 0) && (jDraw > 0)) {
			infos[(i * 3) + 1]--;
			infos[(j * 3) + 1]--;
			dfs(Depth + 1);
			infos[(j * 3) + 1]++;
			infos[(i * 3) + 1]++;
		}
    }
	
	private static void settings() {
		dfs(0);
		Index++;
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int m = 0;
        for (int i = 0; i < 6; i++) {
        	for (int j = (i + 1); j < 6; j++) {
        		matches[m][0] = i;
        		matches[m][1] = j;
        		m++;
        	}
        }

        for (int i = 0; i < 4; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 18; j++) {
            	infos[j] = Integer.parseInt(input[j]);
            }
        	settings();
        }
        

        for (int i = 0; i < 4; i++) {
        	System.out.print(Answers[i] + " ");
        }
        br.close();
    }

}