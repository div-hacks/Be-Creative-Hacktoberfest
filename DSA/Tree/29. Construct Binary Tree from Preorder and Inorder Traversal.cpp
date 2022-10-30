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
private:
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inoMap) {
        
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int ino_root_idx = inoMap[preorder[preStart]];
        int ino_root_leftside = ino_root_idx - inStart;
        
        root->left = constructTree(preorder, preStart+1, preStart+ino_root_leftside, inorder, inStart, ino_root_idx-1, inoMap);
        
        root->right = constructTree(preorder, preStart+ino_root_leftside+1, preEnd, inorder, ino_root_idx+1, inEnd, inoMap);
        
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inoMap;
        
        for(int i=0; i<inorder.size(); i++) {
            inoMap[inorder[i]] = i;
        }
        
        TreeNode* ans_tree_root = constructTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inoMap);
        
        return ans_tree_root;
    }
};