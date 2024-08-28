import java.io.*;
import java.util.*;

public class Main {

	private static int N;
	private static int Answer;
	
	public static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void settings() {
		for (int i = 1; i <= N; i++) {
			if (String.valueOf(i).contains("50")) {
				Answer += 2;
			} else {
				Answer++;
			}
		}
		
		if (String.valueOf(N).contains("50")) {
			Answer--;
		}
		
		find_Answer();
	}
	
	public static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		settings();
	}

	public static void main(String[] args) throws IOException {
		input();
	}

}