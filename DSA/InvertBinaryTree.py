class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        root.left , root.right = self.invertTree(root.right) , self.invertTree(root.left)
        return root