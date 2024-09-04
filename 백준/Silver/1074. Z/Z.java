import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, R, C, Count;
    private static int Answer = -1;
    
    private static void dfs(int Depth, int startY, int startX, int endY, int endX) {
    	if (Depth == 1) {
    		if ((startY == R) && (startX == C)) {
    			Answer = Count;
    		}
    		// System.out.println("(" + startY + ", " + startX + ")");
    		Count++;
    		
    		if ((startY == R) && (endX == C)) {
    			Answer = Count;
    		}
    		// System.out.println("(" + startY + ", " + endX + ")");
    		Count++;
    		
    		if ((endY == R) && (startX == C)) {
    			Answer = Count;
    		}
    		// System.out.println("(" + endY + ", " + startX + ")");
    		Count++;
    		
    		if ((endY == R) && (endX == C)) {
    			Answer = Count;
    		}
    		// System.out.println("(" + endY + ", " + endX + ")");
    		Count++;
    		
    		return;
    	}

    	int half = (int) Math.pow(2, Depth - 1);
    	if ((R >= startY) && (R <= startY + half - 1) && (C >= startX) && (C <= startX + half - 1)) {
        	dfs(Depth - 1, startY, startX, startY + half - 1, startX + half - 1);
    	} else {
    		Count += (half * half);
    	}
    	
    	if ((R >= startY) && (R <= startY + half - 1) && (C >= startX + half) && (C <= endX)) {
        	dfs(Depth - 1, startY, startX + half, startY + half - 1, endX);
    	} else {
    		Count += (half * half);
    	}
    	
    	if ((R >= startY + half) && (R <= endY) && (C >= startX) && (C <= startX + half - 1)) {
        	dfs(Depth - 1, startY + half, startX, endY, startX + half - 1);
    	} else {
    		Count += (half * half);
    	}
    	
    	if ((R >= startY + half) && (R <= endY) && (C >= startX + half) && (C <= endX)) {
        	dfs(Depth - 1, startY + half, startX + half, endY, endX);
    	} else {
    		Count += (half * half);
    	}
    }
	
	private static void settings() {
    	int now = (int) Math.pow(2, N);
        R++;
        C++;
		dfs(N, 1, 1, now, now);
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        R = Integer.parseInt(inputs[1]);
        C = Integer.parseInt(inputs[2]);

        settings();
        
        System.out.println(Answer);
        br.close();
    }

}