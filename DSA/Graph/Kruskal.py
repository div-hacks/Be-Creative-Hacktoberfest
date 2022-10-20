from os import *
from sys import *
from collections import *
from math import *

# Creates a new set consisting of the new element v.
def make_set(v, parent, rank):
    parent[v] = v
    rank[v] = 0

# Returns the parent of the set that contains the element v.
def find_set(v, parent):
    if (v == parent[v]):
        # Current element is the parent of its set.
        return v
    else:
        # Using path compression technique.
        return find_set(parent[v], parent)
        
    
# Merges the two specified sets.
def union_sets(a, b, parent, rank):
    # Find the parent of both elements.
    a = find_set(a, parent)
    b = find_set(b, parent)

    if (a != b):
        if (rank[a] < rank[b]):
            # Swap.
            temp = a
            a = b
            b = temp

        parent[b] = a
        if (rank[a] == rank[b]):
            rank[a] += 1

def kruskalMST(n, m, graph):
    # Parent and rank arrays to be used in DSU.
    parent = [0 for i in range(n + 1)]
    rank = [0 for i in range(n + 1)]

    for i in range(1, n + 1):
        # Create a new set for each node.
        make_set(i, parent, rank)

    # To store the weight of MST.
    cost = 0

    # Sort the edges in ascending order by its weight.
    graph.sort(key=lambda e: e[2])

    # Start traversing through the edges.
    for edge in graph:
        # Check if both vertices of current edge belong to different sets(subtrees).
        if (find_set(edge[0], parent) != find_set(edge[1], parent)):
        
            # Add the weight of the current edge.
            cost = cost + edge[2]

            # Merge the two sets(subtrees).
            union_sets(edge[0], edge[1], parent, rank)

    return cost
