# comp
Programming competitions I've competed in or did for practice.

Here's a list of cool algorithms I've discovered.

Union find
---
Used to perform operations on a disjoint-set data structure.

Initialization:
~~~c++
int link[n], size[n];
for (int i = 0; i < n; i++)
    link[i] = i;
memset(size, 1, sizeof(int)*n);
~~~

Find:
~~~c++
int find(int *link, int x) {
    while (x != link[x]) x = link[x];
    return x;
} 
~~~

Unite:
~~~c++
void unite(int *link, int *size, int a, int b) {
    a = find(link, a);
    b = find(link, b);
    if (size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}
~~~

Euclidean algorithm
---
Used to find the greatest common divisor.
~~~c++
int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
~~~ 

isPrime
---
Used to find if a number is prime.
~~~c++
bool isPrime (int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int m = sqrt(n);

    for (int i = 3; i <= m; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
~~~

The Sieve of Eratosthenes
---
Used to find prime numbers in range.
~~~c++
bool* sieve(int n) {
    bool* prime = new bool[n+1];
    memset(prime, true, sizeof(bool)*(n+1));
    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);

    for (int i = 2; i <= m; i++)
        if (prime[i])
            for (int k = i * i; k <= n; k += i)
                prime[k]=false;
    
    return prime;
}
~~~

Binary Search
---
Used to find an element in a sorted array in O(logn) time.
~~~c++
int binary_search(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) 
            return m;
        else if (nums[m] < target)
            r = m - 1; 
        else if (nums[m] > target)
            l = m + 1;
    }
    return -1;
}
~~~

Bellman-Ford algorithm
---
Used to find shortest path to all nodes from initial node. Supports negative edge weights. O(V*E) where V = number of vertices and E = number of edges. Can also be used to determine if graph has negative cycle by increasing rounds from V-1 to V.
~~~c++
vector<int> bellman_ford(vector<tuple<int,int,int> > E, int V) { 
    vector<int> distance(V, INT_MAX);
    // Starting node
    distance[0] = 0;
    // Maximum path = V-1 edges
    for (int i = 0; i < V-1; i++) {
        for (auto edge : E) {
            int a, b, w;
            tie(a, b, w) = edge;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
    return distance;
}
~~~

Dijkstra's algorithm
---
Used to find shortest path to all nodes from initial node. Does not support negative weights. O(V + E*log(E)).  
~~~c++
vector<int> dijkstra(vector<vector<pair<int,int> > > graph) {
    vector<int> distance(graph.size(), INT_MAX);
    distance[0] = 0;
    priority_queue<pair<int,int> > q;
    q.push({0,0});
    unordered_set<int> processed;
    while (!q.empty()) {
        int a = q.front().second;
        q.pop();
        if (processed.find(a) != processed.end()) continue;
        processed.insert(a);
        for (pair<int,int>& edge : graph[a]) {
            int b = edge.first, w = edge.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    return distance;
}
~~~
