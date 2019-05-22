Chapter 13: Shortest paths
===
 * Finding shortest path is incredibly important problem. 
 * In unweighted graphs, we can just use BFS to solve for shortest paths
 * This chapter will focus on weighted graphs

Bellman-Ford algorithm
---
 * Finds paths from starting node to all other nodes
 * Can detect negative cycles, but does not account for it
 * ![bellman-ford](./images/bellman-ford.png)
 * Implemented fairly easily using two for loops. tie(a,b,w) gets a, b, and w from e.  
 * ~~~c++
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[x] = 0;
	for (int i = 1; i <= n-1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}
   ~~~
 * To detect negative cycle, run `n` rounds instead of `n-1`. If anything decreases, there's a negative cycle.

Dijkstra's algorithm
---
 * Finds paths from starting node to all other nodes
 * More efficient than Bellman-Ford, but harder to implement
 * Requires no negative weights
 * 
