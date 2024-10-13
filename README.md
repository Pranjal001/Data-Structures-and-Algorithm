# Data-Structures-and-Algorithm
Theory and codes for standard Data structures and algorithms

## GRAPH
### (1) DFS/DSU - Count No of Component
### (2) BFS - Shortest path / store dir for backtracking.
### (3) DFS/DSU - No of edges required to connect Component/cities.
### (4) BFS - Shortest path and Store parent and backtrack for printing path. 
### (5) Bipartite - 2 Color problem, assign color to node, traverse child, if(visited) check() else dfs;
### (6) Cycle Detection - store last node of cycle and again use dfs to print cycle start from last node to last node.
### (7) BFS - store monster first then start node and store direction in grid for backtracking.
### (8) Dijkstra / minimum cost - use priority queue.
### (9) Floyd Warshall - multi edges thus store min cost while building adj list.
### (10) Bell man ford / max cost / min cost  - (a) Use 2 time to propogate +ve/ -ve cycle to all node return -1 (b) Use 2 dfs forward and backward to check if node reachable from src and dst.. during N'th relaxation if u and v both are visited thus +ve cycle on src to dst path.
### (11) Dijkstra - 2 time dj(u,v) and dj(v,u), use discount on each node to minimum cost, all edge x max(dist1[a] + x/2 + dist2[b]), where dist1[a] is min cost from u to a and dist2[b] is min cost from v to b and x is curr edge b/w a and b.
### (12) Bell Man Ford - store parent to print cycle, once node get relax nth time then backtrack n - 1 times to ensure it lie on cycle always.
### (13) Dijkstra/ K minimum cost path - maintain priority queue for each node. 
### (14) Same as (6), only difference is cycle len greater than 1
### (15) Topological Sort
### (16) 