'''
    Time complexity: O(E*log(V))
    Space complexity: O(V^2)

    Where 'E' is the number of edges and 'V' is 
    the number of vertices in a graph.
'''

import sys
import heapq


def dijkstraHelper(adjacencyList, vertices, source):
    pq = []
    distance = [2147483647 for i in range(vertices)]

    # Push the source vertex in the priority queue.
    pq.append([0, source])

    # Distance of a vertex to itself is 0.
    distance[source] = 0
    visited = [False for i in range(vertices)]

    # Loop till all vertices are visited.
    while (len(pq) > 0):
        pair = heapq.heappop(pq)
        u = pair[1]
        visited[u] = True

        # Update the distances of the adjacent nodes.
        for it in adjacencyList[u]:
            v = it[0]
            dist = it[1]

            if (visited[v] == False and distance[v] > distance[u] + dist):
                distance[v] = distance[u] + dist
                heapq.heappush(pq, (distance[v], v))

    return distance


def dijkstra(vec, vertices, edges, source):
    adjacencyList = [[] for j in range(vertices)]
    
    # Create an adjacency list.
    for i in range(len(vec)):
        adjacencyList[vec[i][0]].append([vec[i][1], vec[i][2]])
        adjacencyList[vec[i][1]].append([vec[i][0], vec[i][2]])

    return dijkstraHelper(adjacencyList, vertices, 0)
