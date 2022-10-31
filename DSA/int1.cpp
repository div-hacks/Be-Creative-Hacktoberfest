//687. Longest Univalue Path

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
    int ans;
    int dfs_arrow(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs_arrow(root->left);
        int right = dfs_arrow(root->right);
        
        int leftArrow = 0, rightArrow = 0;
        if(root->left && root->left->val == root->val)
            leftArrow = left + 1;
        if(root->right && root->right->val == root->val)
            rightArrow = right + 1;
        
        ans = max(ans, leftArrow + rightArrow);
        return max(leftArrow, rightArrow);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs_arrow(root);
        return ans;
    }
};
