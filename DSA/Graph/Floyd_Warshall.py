def floydWarshall(n, m, src, dest, edges):
    # Write your code here.
    dist=[[0 for i in range(n + 1)] for j in range(n + 1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i==j:
                dist[i][j]=0
            else:
                dist[i][j]=1000000000
    for i in range(m):
        u=edges[i][0]
        v=edges[i][1]
        w=edges[i][2]
        dist[u][v]=w
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if dist[i][k]!=1000000000 and dist[k][j]!=1000000000:
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j])
    return dist[src][dest]
    
