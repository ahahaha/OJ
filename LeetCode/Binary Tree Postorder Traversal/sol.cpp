/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <set>
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if(root == NULL) return vector<int >();
        
        vector<int > ret;
        stack<TreeNode* > stk;
        set<TreeNode* > vis;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* ptr = stk.top();
            stk.pop();
            if(vis.find(ptr) == vis.end()) {
                vis.insert(ptr);
                stk.push(ptr);
                if(ptr->right != NULL) stk.push(ptr->right);
                if(ptr->left != NULL) stk.push(ptr->left);
            }else {
                ret.push_back(ptr->val);
            }
        }
        
        return ret;
    }
};
