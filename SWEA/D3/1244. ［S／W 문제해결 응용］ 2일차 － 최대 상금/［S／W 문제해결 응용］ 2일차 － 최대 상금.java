import java.io.*;
import java.util.*;

public class Solution {

	private static String S;
	private static int N;
	private static Set<String> visited;
	private static int Answer;
	
	private static void init() {
		visited = new HashSet<String>();
		Answer = 0;
	}
	
	private static void dfs(int Depth, String Now) {
		if (Depth == N) {
			Answer = Math.max(Answer, Integer.parseInt(Now));
			return;
		}
		
		for (int i = 0; i < (S.length() - 1); i++) {
			for (int j = (i + 1); j < S.length(); j++) {
				String Next = "";
				char tmp = Now.charAt(i);
				char tmp2 = Now.charAt(j);
				for (int k = 0; k < S.length(); k++) {
					if (k == i) {
						Next += tmp2;
					} else if (k == j) {
						Next += tmp;
					} else {
						Next += Now.charAt(k);
					}
				}
				
				if (!visited.contains(Next + Depth)) {
					visited.add(Next + Depth);
					dfs(Depth + 1, Next);
				}
			}
		}
	}
	
	private static void settings() {
		dfs(0, S);
	}
	
	public static void main(String[] args) throws IOException {
        // System.setIn(new FileInputStream("1244_input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
         
        StringBuilder sb = new StringBuilder();
         
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            init();

            String[] inputs = br.readLine().split(" ");
            S = inputs[0];
            N = Integer.parseInt(inputs[1]);
            
            settings();

            sb.append("#" + test_case + " ");
            sb.append(Answer + "\n");
        }
         
        bw.write(sb.toString());
        bw.close();
        br.close();
    }
	
}