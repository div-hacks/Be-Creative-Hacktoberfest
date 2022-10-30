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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            
            TreeNode* node = tmp.first;
            int x = tmp.second.first;
            int y = tmp.second.second;
            
            nodes[x][y].insert(node->val);
            
            if(node->left != NULL) {
                q.push({node->left,{x-1,y+1}});
            }
            
            if(node->right != NULL) {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto m : nodes) {
            vector<int> col;
            
            for(auto mm : m.second) {
                for(auto it: mm.second) col.push_back(it);
                // We can use the below code also instead of the above code:
                // col.insert(col.end(), mm.second.begin(), mm.second.end());
            }
            
            ans.push_back(col);
        }
        
        return ans;
        
    }
};