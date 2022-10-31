// 129. Sum Root to Leaf Numbers
// leetcode

// Jtech interview question

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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            auto [n, cur] = q.front(); q.pop();
            cur = cur * 10 + n -> val;
            if(n -> left) q.push({n -> left, cur});      
            if(n -> right) q.push({n -> right, cur});
            if(!n -> left && !n -> right) sum += cur;   // add to total sum if we are at leaf node
        }
        return sum;
    }
};
