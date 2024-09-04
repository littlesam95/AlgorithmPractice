import java.io.*;
import java.util.*;

public class Solution {
	
	private static class Position {
		
		int x, y;

		public Position(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Position [x=" + x + ", y=" + y + "]";
		}
		
	}

	private static int N;
	private static Position Company, House;
	private static List<Position> people;
	private static boolean[] visited = new boolean[11];
	private static int Answer;
	
	private static void init() {
		people = new ArrayList<>();
		for (int i = 0; i < 11; i++) {
			visited[i] = false;
		}
		Answer = Integer.MAX_VALUE;
	}
	
	private static void dfs(int Depth, int Now, int Sum) {
		int nowX = people.get(Now).x;
		int nowY = people.get(Now).y;
		
		if (Depth == N) {
			int houseX = House.x;
			int houseY = House.y;
			int Len = Math.abs(houseX - nowX) + Math.abs(houseY - nowY);
			
			Answer = Math.min(Answer, Sum + Len);
			return;
		}
		
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				int nextX = people.get(i).x;
				int nextY = people.get(i).y;
				int Len = Math.abs(nowX - nextX) + Math.abs(nowY - nextY);
				visited[i] = true;
				dfs(Depth + 1, i, Sum + Len);
				visited[i] = false;
			}
		}
	}
	
	private static void settings() {
		for (int i = 0; i < N; i++) {
			int Len = Math.abs(Company.x - people.get(i).x) + Math.abs(Company.y - people.get(i).y);
			visited[i] = true;
			dfs(1, i, Len);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
        // System.setIn(new FileInputStream("1247_input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
         
        StringBuilder sb = new StringBuilder();
         
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            init();

            N = Integer.parseInt(br.readLine());
            String[] inputs = br.readLine().split(" ");
            Company = new Position(Integer.parseInt(inputs[0]), Integer.parseInt(inputs[1]));
            House = new Position(Integer.parseInt(inputs[2]), Integer.parseInt(inputs[3]));
            for (int i = 0; i < (N * 2); i += 2) {
            	people.add(new Position(Integer.parseInt(inputs[i + 4]), Integer.parseInt(inputs[i + 5])));
            }
            
            settings();

            sb.append("#" + test_case + " ");
            sb.append(Answer + "\n");
        }
         
        bw.write(sb.toString());
        bw.close();
        br.close();
    }
	
}