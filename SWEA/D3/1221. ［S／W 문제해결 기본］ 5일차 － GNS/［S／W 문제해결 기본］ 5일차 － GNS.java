import java.io.*;
import java.util.*;
 
public class Solution {
 
    private static int N;
    private static Map<Integer, String> hm = new HashMap<>();
    private static List<Integer> numbers = new ArrayList<>();
    private static StringBuilder Answer = new StringBuilder();
     
    private static void init() {
        numbers.clear();
    }
     
    private static void settings() {
        Collections.sort(numbers);
        for (int i = 0; i < N; i++) {
            Answer.append(" " + hm.get(numbers.get(i)));
        }
    }
     
    public static void main(String[] args) throws IOException {
        // System.setIn(new FileInputStream("1221_input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
 
        hm.put(0, "ZRO");
        hm.put(1, "ONE");
        hm.put(2, "TWO");
        hm.put(3, "THR");
        hm.put(4, "FOR");
        hm.put(5, "FIV");
        hm.put(6, "SIX");
        hm.put(7, "SVN");
        hm.put(8, "EGT");
        hm.put(9, "NIN");
          
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            init();
             
            String[] inputs = br.readLine().split(" ");
            String case_number = inputs[0];
            N = Integer.parseInt(inputs[1]);
            inputs = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                String now = inputs[i];
                switch(now) {
                case "ZRO":
                    numbers.add(0);
                    break;
                case "ONE":
                    numbers.add(1);
                    break;
                case "TWO":
                    numbers.add(2);
                    break;
                case "THR":
                    numbers.add(3);
                    break;
                case "FOR":
                    numbers.add(4);
                    break;
                case "FIV":
                    numbers.add(5);
                    break;
                case "SIX":
                    numbers.add(6);
                    break;
                case "SVN":
                    numbers.add(7);
                    break;
                case "EGT":
                    numbers.add(8);
                    break;
                case "NIN":
                    numbers.add(9);
                    break;
                }
            }
 
            Answer.append(case_number);
            settings();
            Answer.append("\n");
        }
          
        bw.write(Answer.toString());
        bw.close();
        br.close();
    }
     
}