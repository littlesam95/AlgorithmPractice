import java.io.*;
import java.util.*;

public class Main {
	
	private static int T, N, M;
	private static long[][] dp = new long[31][31];
	private static StringBuilder sb = new StringBuilder();
	
	private static void init() {
		for (int i = 1; i < 31; i++) {
			dp[i][0] = 1;
			dp[i][i] = 1;
		}
		for (int i = 2; i < 31; i++) {
			for (int j = 1; j < i; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        init();

        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
        	String[] inputs = br.readLine().split(" ");
        	N = Integer.parseInt(inputs[0]);
        	M = Integer.parseInt(inputs[1]);
        	sb.append(dp[M][N] + "\n");
        }

        bw.write(sb.toString());
        bw.close();
        br.close();
    }

}