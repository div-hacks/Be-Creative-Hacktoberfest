// 124. Binary Tree Maximum Path Sum
// leetcode
// JTech interview question


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum;
    int dfs_path_sum(TreeNode* root){
        if(!root) return 0;
        
        int left = max(0, dfs_path_sum(root->left));
        int right = max(0, dfs_path_sum(root->right));
        
        sum = max(sum, root->val + left + right);
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        sum = INT_MIN;
        dfs_path_sum(root);
        
        return sum;
    }
};
