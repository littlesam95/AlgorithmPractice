import java.io.*;

public class Main {
	
	public static void find_Answer(long Answer) {
		System.out.println(Answer);
	}
	
	public static void settings(int N, String[] A) {
		long Sum = 0;
		
		for (int i = 0; i < N; i++) {
			Sum += Long.parseLong(A[i]);
		}
		
		long Answer = 0;
		
		for (int i = 0; i < (N - 1); i++) {
			Answer += Long.parseLong(A[i]) * (Sum - Long.parseLong(A[i]));
			Sum -= Long.parseLong(A[i]);
		}
		
		find_Answer(Answer);
	}
	
	public static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] A = br.readLine().split(" ");
		settings(N, A);
	}

	public static void main(String[] args) throws IOException {
		input();
	}

}