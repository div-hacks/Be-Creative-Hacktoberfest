''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    Following is the TreeNode class structure

    class TreeNode:

        def __init__ (self, data):

            self.data = data
            self.left = None
            self.right = None
            
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
def floorInBST(root, X):

    # Write your Code here.
    cur=root
    ans=-1
    while cur:
        if cur.data > X:
            cur=cur.left
        else:
            ans=cur.data
            cur=cur.right
    return ans
