import java.io.*;

public class Main {
	
	private static int N;
	private static int Answer = Integer.MAX_VALUE;
	
	private static void settings() {
		if (N % 3 == 0) {
			Answer = (N / 3);
		}
		int F = N / 5;
		for (int i = F; i >= 0; i--) {
			int R = N - (i * 5);
			if (R % 3 == 0) {
				Answer = Math.min(Answer, i + (R / 3));
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        settings();
        
        if (Answer == Integer.MAX_VALUE) {
        	System.out.println("-1");
        } else {
        	System.out.println(Answer);
        }
    }

}