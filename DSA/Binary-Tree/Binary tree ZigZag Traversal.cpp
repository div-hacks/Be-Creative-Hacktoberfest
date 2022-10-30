/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).*/

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
class Solution
{

public:
  vector < vector > zigzagLevelOrder (TreeNode * root)
  {

    vector < vector > ans;

    queue < TreeNode * >q;

    if (root == NULL)
      return ans;

    q.push (root);

    int j = 0;

    while (!q.empty ())
      {

	int size = q.size ();

	vector level;

	for (int i = 0; i < size; i++)
	  {

	    TreeNode *node = q.front ();

	      q.pop ();

	    if (node->left != NULL)
	        q.push (node->left);

	    if (node->right != NULL)
	        q.push (node->right);

	      level.push_back (node->val);

	  }

	if (j % 2 == 0)
	  {

	    ans.push_back (level);

	  }

	else
	  {

	    reverse (level.begin (), level.end ());

	    ans.push_back (level);

	  }

	j++;

      }

    return ans;

  }

};

/*Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]*/
