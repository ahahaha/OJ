import java.util.*;
public class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens.length <= 1) return Integer.valueOf(tokens[0]);
        
        Stack<String> stk = new Stack<String>();
        for(int i = 0; i < tokens.length; i++) {
            while(!isOper(tokens[i])) {
                stk.push(tokens[i]);
                i++;
            }
            
            int x = Integer.valueOf(stk.pop());
            int y = Integer.valueOf(stk.pop());
            int z;
            if(tokens[i].equals("+")) {
                z = x + y;
            }else if(tokens[i].equals("-")) {
                z = y - x;
            }else if(tokens[i].equals("*")) {
                z = x * y;
            }else {
                z = y / x;
            }
            stk.push(String.valueOf(z));
        }
        
        return Integer.valueOf(stk.peek());
    }
    
    public boolean isOper(String str) {
        if(str.equals("+") || str.equals("-")
            || str.equals("*") || str.equals("/"))
            return true;
        return false;
    }
}
