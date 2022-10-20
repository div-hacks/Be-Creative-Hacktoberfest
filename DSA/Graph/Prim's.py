from os import *
from sys import *
from collections import *
from math import *

def calculatePrimsMST(n, m, g):
    # Write your code here.
    # Return a 2-D list.
    graph=[[0 for i in range(n+1)] for j in range(n+1)]
    for u,v,w in g:
        graph[u][v]=w
    selected=[0]*(n+1)
    e=0
    selected[1]=1
    ans=[]
    while e<n-1:
        mini=100000000
        x=0
        y=0
        for i in range(1,n+1):
            if selected[i]:
                for j in range(1,n+1):
                    if selected[j]==0 and graph[i][j]:
                        if mini>graph[i][j]:
                            mini=graph[i][j]
                            x=i
                            y=j
        ans.append([x,y,graph[x][y]])
        selected[y]=1
        e+=1
    return ans
