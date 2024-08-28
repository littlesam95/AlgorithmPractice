import java.io.*;
import java.util.*;

public class Main {
	
	private static class Enemy {
		int Y, X;
		boolean hunted;
		
		public Enemy(int Y, int X, boolean hunted) {
			this.Y = Y;
			this.X = X;
			this.hunted = hunted;
		}
	}
	
	private static int N, M, D;
	private static int[][] map = new int[16][16];
	private static ArrayList<Enemy> originalEnemies = new ArrayList<>();
	private static boolean[] archers = new boolean[16];
	private static int[] archerPos = new int[3];
	private static int Answer = 0;
	
	private static void simulate() {
		int nowCount = 0;
		ArrayList<Enemy> enemies = new ArrayList<>();
		for (int i = 0; i < originalEnemies.size(); i++) {
			enemies.add(new Enemy(originalEnemies.get(i).Y, originalEnemies.get(i).X, originalEnemies.get(i).hunted));
		}
		
		while (true) {
			if (enemies.isEmpty()) break;
			
			// 모든 궁수가 동시에 공격
			for (int i = 0; i < 3; i++) {
				int final_dist = Integer.MAX_VALUE;
				int final_left_pos = M;
				int final_enemy_index = -1;
				
				// 거리가 D 이하인 적 중 가장 가깝고 가장 왼쪽에 있는 적을 선택
				for (int j = 0; j < enemies.size(); j++) {
					int now_dist = Math.abs(enemies.get(j).Y - N) + Math.abs(enemies.get(j).X - archerPos[i]);
					if (now_dist <= D) {
						if (now_dist < final_dist) {
							final_dist = now_dist;
							final_left_pos = enemies.get(j).X;
							final_enemy_index = j;
						} else if (now_dist == final_dist) {
							if (enemies.get(j).X < final_left_pos) {
								final_dist = now_dist;
								final_left_pos = enemies.get(j).X;
								final_enemy_index = j;
							}
						}
					}
				}
				
				if (final_enemy_index != -1) {
					enemies.get(final_enemy_index).hunted = true;
				}
			}
			
			// 공격받은 적은 게임에서 제외
			for (int i = 0; i < enemies.size(); i++) {
				if (enemies.get(i).hunted) {
					enemies.remove(i);
					i--;
					nowCount++;
				}
			}
			
			
			// 궁수의 공격이 끝나면 적이 이동
			for (int i = 0; i < enemies.size(); i++) {
				enemies.get(i).Y++;
				if (enemies.get(i).Y >= N) {
					enemies.remove(i);
					i--;
				}
			}
			
		}
		
		Answer = Math.max(Answer, nowCount);
	}
	
	private static void settings(int Depth, int Start) {
		if (Depth == 3) {
			simulate();
			return;
		}
		
		for (int i = Start; i < M; i++) {
			if (!archers[i]) {
				archerPos[Depth] = i;
				archers[i] = true;
				settings(Depth + 1, i + 1);
				archers[i] = false;
				archerPos[Depth] = -1;
			}
		}
	}
	
	private static void find_Answer() {
		System.out.println(Answer);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        D = Integer.parseInt(inputs[2]);
        for (int i = 0; i < N; i++) {
        	inputs = br.readLine().split(" ");
        	for (int j = 0; j < M; j++) {
        		map[i][j] = Integer.parseInt(inputs[j]);
        		if (map[i][j] == 1) {
        			originalEnemies.add(new Enemy(i, j, false));
        		}
        	}
        }
		
		settings(0, 0);
		find_Answer();
	}
}