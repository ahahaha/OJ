/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return new ArrayList<Integer>();
        
        Stack<TreeNode> stk = new Stack<TreeNode>();
        ArrayList<Integer> ret = new ArrayList<Integer>();
        HashSet<TreeNode> vis = new HashSet<TreeNode>();
        
        stk.push(root);
        while(!stk.empty()) {
            TreeNode ptr = stk.pop();
            if(!vis.contains(ptr)) {
                vis.add(ptr);
                stk.push(ptr);
                if(ptr.right != null)
                    stk.push(ptr.right);
                if(ptr.left != null)
                    stk.push(ptr.left);
            }else {
                ret.add(ptr.val);
            }
        }
        
        return ret;
    }
}
