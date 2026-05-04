import heapq

def dijkstra(n, adj, source):
    dist = [float('inf')] * n
    dist[source] = 0
    h = [(0, source)]
    while q:
        d, u = heapq.heappop(q)
        if dist[u] < d: continue
        dist[u] = d
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = dist[u] + w
                heapq.heappush(q, (dist[v], v))
    return dist
