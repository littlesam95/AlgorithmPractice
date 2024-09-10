import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, K;
	private static int[] W = new int[101];
	private static int[] V = new int[101];
	private static int[] dp = new int[100001];
	private static StringBuilder sb = new StringBuilder();
	
	private static void settings() {
		for (int i = 1; i <= N; i++) {
			for (int j = K; j >= 0; j--) {
				if (j - W[i] >= 0) {
					dp[j] = Math.max(dp[j], dp[j - W[i]] + V[i]);
				}
			}
		}
		
		sb.append(dp[K] + "\n");
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);
        for (int i = 1; i <= N; i++) {
        	inputs = br.readLine().split(" ");
        	W[i] = Integer.parseInt(inputs[0]);
        	V[i] = Integer.parseInt(inputs[1]);
        }
        
        settings();
        
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

}