import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, M, cSum;
	private static int[] A = new int[101];
	private static int[] C = new int[101];
	private static int[][] dp = new int[101][10001];
	private static int Answer = Integer.MAX_VALUE;
	private static StringBuilder sb = new StringBuilder();
	
	private static void settings() {
		for (int i = 1; i <= N; i++) {
			for (int j = cSum; j >= 0; j--) {
				if (j - C[i] >= 0) {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - C[i]] + A[i]);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		
		for (int i = 0; i <= cSum; i++) {
			if (dp[N][i] >= M) {
				Answer = i;
				break;
			}
		}
		sb.append(Answer + "\n");
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        inputs = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
        	A[i] = Integer.parseInt(inputs[i - 1]);
        }
        inputs = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
        	C[i] = Integer.parseInt(inputs[i - 1]);
        	cSum += C[i];
        }
        
        settings();
        
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

}