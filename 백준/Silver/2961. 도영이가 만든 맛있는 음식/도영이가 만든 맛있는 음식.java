import java.io.*;
import java.util.*;

public class Main {
	
	private static class Ingredient {
		int Sour, Bitten;
		
		public Ingredient(int Sour, int Bitten) {
			this.Sour = Sour;
			this.Bitten = Bitten;
		}
	}
	
	private static int N;
	private static ArrayList<Ingredient> ingredients = new ArrayList<>();
	private static boolean[] visited = new boolean[10];
	private static int Answer = Integer.MAX_VALUE;
	
	private static void settings(int Depth, int Sour, int Bitten) {
		if (Depth > 0) {
			Answer = Math.min(Answer, Math.abs(Sour - Bitten));
		}
		
		if (Depth == N) {
			return;
		}
		
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				settings(Depth + 1, Sour * ingredients.get(i).Sour, Bitten + ingredients.get(i).Bitten);
				visited[i] = false;
			}
		}
	}
	
	private static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			String[] inputs = br.readLine().split(" ");
			ingredients.add(new Ingredient(Integer.parseInt(inputs[0]), Integer.parseInt(inputs[1])));
		}
		
		settings(0, 1, 0);
		find_Answer();
	}

}