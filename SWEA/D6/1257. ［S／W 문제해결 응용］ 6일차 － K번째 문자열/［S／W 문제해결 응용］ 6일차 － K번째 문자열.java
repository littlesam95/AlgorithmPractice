import java.io.*;
import java.util.*;

public class Solution {

	private static int K;
	private static String S;
	private static Set<String> set = new TreeSet<>();
    private static StringBuilder Answer = new StringBuilder();
	
	private static void init() {
		set.clear();
	}
	
	private static void settings() {
		for (int i = 0; i < S.length(); i++) {
			for (int j = i; j < S.length(); j++) {
				String now = S.substring(i, j + 1);
				set.add(now);
			}
		}
		
		int Index = 1;
		for (String s : set) {
			if (Index == K) {
				Answer.append(s);
				return;
			}
			Index++;
		}
		Answer.append("none");
	}
	
	public static void main(String[] args) throws IOException {
        // System.setIn(new FileInputStream("1257_input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
         
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            init();

            Answer.append("#" + test_case + " ");
            K = Integer.parseInt(br.readLine());
            S = br.readLine();
            settings();
            Answer.append("\n");
        }
         
        bw.write(Answer.toString());
        bw.close();
        br.close();
    }
	
}