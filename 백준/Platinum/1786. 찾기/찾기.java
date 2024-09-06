import java.io.*;
import java.util.*;

public class Main {
	
	private static String T, P;
	private static List<Integer> Answer = new ArrayList<>();
	
	private static void settings() {
		int tLength = T.length();
		int pLength = P.length();

		int[] pi = new int[pLength];
		
		for (int i = 1, j = 0; i < pLength; i++) {
			while ((j > 0) && (P.charAt(i) != P.charAt(j))) {
				j = pi[j - 1];
			}
			
			if (P.charAt(i) == P.charAt(j)) {
				pi[i] = ++j;
			}
		}
		
		for (int i = 0, j = 0; i < tLength; i++) {
			while ((j > 0) && (T.charAt(i) != P.charAt(j))) {
				j = pi[j - 1];
			}
			
			if (T.charAt(i) == P.charAt(j)) {
				if (j == pLength - 1) {
					Answer.add(i - pLength + 2);
					j = pi[j];
				} else {
					j++;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = br.readLine();
        P = br.readLine();
        settings();
        
        System.out.println(Answer.size());
        for (int i = 0; i < Answer.size(); i++) {
            System.out.print(Answer.get(i) + " ");
        }
        br.close();
    }

}