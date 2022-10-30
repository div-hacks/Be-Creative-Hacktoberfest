from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the TreeNode class structure
   
    class   TreeNode :
        def __init__(self, data) :
            self.data = data
            self.left = None
            self.right = None

        def __del__(self):
            if self.left:
                del self.left
            if self.right:
                del self.right

'''
def kthSmallest(root, k):
    c=0
    s=-99999
    cur=root
    while cur:
        if cur.left==None:
            c+=1
            if c==k:
                s=cur.data
            cur=cur.right
        else:
            pre=cur.left
            while pre.right and pre.right!=cur:
                pre=pre.right
            if pre.right==None:
                pre.right=cur
                cur=cur.left
            else:
                pre.right=None
                c+=1
                if c==k:
                    s=cur.data
                cur=cur.right
    return s
