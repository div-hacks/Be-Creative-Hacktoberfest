from os import *
from sys import *
from collections import *
from math import *

'''

    ------- Binary Tree node structure --------
            class TreeNode :
                def __init__(self, data):
                    self.data = data
                    self.left = None
                    self.right = None
                    
                def __del__(self):
                    if self.left:
                        del self.left
                    if self.right:
                        del self.right
                        
'''

def KthLargestNumber(root, k):

	# Write your code here.
    c=0
    l=-1
    cur=root
    while cur:
        if cur.right==None:
            c+=1
            if c==k:
                l=cur.data
            cur=cur.left
        else:
            suc=cur.right
            while suc.left and suc.left!=cur:
                suc=suc.left
            if suc.left==None:
                suc.left=cur
                cur=cur.right
            else:
                suc.left=None
                c+=1
                if c==k:
                    l=cur.data
                cur=cur.left
    return l
