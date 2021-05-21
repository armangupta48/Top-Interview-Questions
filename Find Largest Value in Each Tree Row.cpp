/*

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,null,2]
Output: [1,2]
Example 5:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        int level = 0;
        vector<int> res;
        helper(root,res,level);
        return res;
    }
    void helper(TreeNode* root,vector<int>& res,int level)
    {
        if(!root) return;
        if(level<res.size()) res[level] = max(root->val,res[level]);
        else
            res.push_back(root->val);
        helper(root->left,res,level+1);
        helper(root->right,res,level+1);
    }
};
