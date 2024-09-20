import java.io.*;
import java.util.*;

class Solution {
	
	private static class Item implements Comparable<Item> {
		
		String S;

		public Item(String s) {
			super();
			S = s;
		}

		@Override
		public int compareTo(Item o) {
			if (this.S.charAt(M) == o.S.charAt(M)) {
				return this.S.compareTo(o.S);
			}
			return this.S.charAt(M) - o.S.charAt(M);
		}
		
	}
	
	private static int N, M;
	private static List<Item> items = new ArrayList<>();
    
    public String[] solution(String[] strings, int n) {
        M = n;
        for (int i = 0; i < strings.length; i++) {
			items.add(new Item(strings[i]));
		}
		
		Collections.sort(items);
        String[] answer = new String[strings.length];
        for (int i = 0; i < strings.length; i++) {
			answer[i] = items.get(i).S;
		}
        
        return answer;
    }
}