import java.util.*;

class Solution {
    
    private class Node {
        
        HashMap<Character, Node> Children;
        boolean isEnd;
        
        public Node() {
            this.Children = new HashMap<Character, Node>();
            this.isEnd = false;
        }
        
    }
    
    private class Trie {
        
        Node Root;
        
        public Trie() {
            this.Root = new Node();
        }
        
        public boolean insertPattern(String pattern) {
            Node node = this.Root;
            boolean Flag = true;
            
            for (int i = 0; i < pattern.length(); i++) {
                char Now = pattern.charAt(i);
                if (!node.Children.containsKey(Now)) {
                    node.Children.put(Now, new Node());
                }
                node = node.Children.get(Now);
                if (node.isEnd) {
                    return true;
                }
            }
            
            if (!node.isEnd) {
                node.isEnd = true;
                if (!node.Children.isEmpty()) {
                    return true;
                }
            }
            return false;
        }
        
    }
    
    private Trie root = new Trie();
    
    public boolean solution(String[] phone_book) {
        for (int i = 0; i < phone_book.length; i++) {
            String Now = phone_book[i];
            if (root.insertPattern(Now)) {
                return false;
            }
        }
        
        return true;
    }
    
}