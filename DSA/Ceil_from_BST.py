from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the TreeNode class structure

    class TreeNode:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
'''
def findCeil(root, x):
    # Write your code here.
    curr=root
    ans=-1
    while curr:
        if curr.data<x:
            curr=curr.right
        else:
            ans=curr.data
            curr=curr.left
    return ans
