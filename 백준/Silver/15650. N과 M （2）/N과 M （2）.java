import java.io.*;
import java.util.*;

public class Main {
	
	private static int N;
	private static int M;
	private static int[] numbers = new int[9];
	private static boolean[] visited = new boolean[9];
	
	private static void settings(int Start, int Depth) {
		if (Depth == M) {
			for (int i = 0; i < M; i++) {
				System.out.print(numbers[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for (int i = Start; i <= N; i++) {
			if (visited[i]) continue;
			numbers[Depth] = i;
			visited[i] = true;
			settings(i + 1, Depth + 1);
			visited[i] = false;
			numbers[Depth] = 0;
		}
	}

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        settings(1, 0);
	}
}