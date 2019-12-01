# competitive\_programming 

A collection of solutions to competitive programming problems.

This repository is currently split into three folders:
* `comp` for problems from competitions
* `leetcode` for problems from Leetcode (interview type problems)
* `own` for a sandbox (i.e. invent own problems) 

## Algorithms

Union find
---
Used to perform operations on a disjoint-set data structure. Find and Unite time: O(log(n)).
~~~c++
class UnionFind {
public:
    int *link, *size;

    UnionFind(int n) {
        link = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
            link[i] = i;
        memset(size, 1, sizeof(int)*n);
    }

    int find(int x) {
        while (x != link[x]) x = link[x];
        return x;
    } 

    void unite(int a, int b) {
        a = find(link, a);
        b = find(link, b);
        if (size[a] < size[b]) swap(a,b);
        size[a] += size[b];
        link[b] = a;
    }
};
~~~

Euclidean algorithm
---
Used to find the greatest common divisor. Time: O(log(a) + log(b)).
~~~c++
int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
~~~ 

Extended Euclidean algorithm
---
Used to find coefficients `x` and `y` such that `ax + by = gcd(a, b)`.
~~~c++
int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
~~~

Least common multiple
---
Used to find the least common multiple.
~~~c++
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
~~~

Triangle inequality theorem
---
Test to see if three side lengths can make a valid triangle. Time: O(1).
~~~c++
bool valid_triangle(int a, int b, int c) {
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;
    return true;
}
~~~

isPrime
---
Used to find if a number is prime. Time: O(sqrt(n)).
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
Used to find prime numbers in range. Time: O(n*log(log(n))).
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
Used to find an element in a sorted array. Time: O(log(n)).
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
Used to find shortest path to all nodes from initial node. Supports negative edge weights. Time: O(V*E). 
~~~c++
vector<int> bellman_ford(vector<tuple<int,int,int> > E, int V) { 
    // E[i] = {src, dst, weight}
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
    priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    // Where first = total distance, second = node
    // Priority queue sorts in increasing order 
    q.push({0,0});
    unordered_set<int> processed;
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed.find(a) != processed.end()) continue;
        processed.insert(a);
        for (pair<int,int>& edge : graph[a]) {
            int b = edge.first, w = edge.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }
    return distance;
}
~~~

Floyd-Warshall algorithm
---
Used to find shortest paths from all nodes to all nodes that are represented in an adjacency list. Time: O(n<sup>3</sup>). 
~~~c++
void floydwarshall(vector<vector<int> > graph) {
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                graph[i][j] = min(graph[i][j],
                                  graph[i][k] + graph[k][j]);
            }
        }
    }
    return;
}
~~~

Kahn's algorithm
---
Used to perform topological sort. Time: O(V + E).
~~~c++
vector<Node*> kahn(vector<Node*> graph) {
    unordered_map<Node*, int> num_connections;
    vector<Node*> res;
    vector<Node*> fringe;
    // Populate num_connections
    for (auto& n : graph)
        for (auto& e : n->edges)
            num_connections[e]++;
    // Populate fringe 
    for (auto it = num_connections.begin(); it != num_connections.end(); it++)
        if (it.second == 0)
            fringe.push_back(it.first);
    // Begin algorithm
    while (!fringe.empty()) {
        vector<Node*> new_fringe;
        for (auto& n : fringe) {
            res.push_back(n);
            for (auto& e : n->edges) {
                num_connections[e]--;
                if (num_connections[e] == 0)
                    new_fringe.push_back(e);
            }
        }
        fringe = new_fringe;
    }
    // Warning: If center of graph has cycle, cycle will not be added to res.
    return res;
}
~~~  

Segment tree
---
Used to perform range queries on mutable arrays. The example below is for sum queries. Creating tree: O(n) time, O(4*n) memory. Update and query are O(log(n)).
~~~c++
class SegmentTree {
public:
    int size;
    vector<int> tree;
    
    // Usage: (1, 0, this->size, i, j) for sum of [i, j]
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (tl == l && tr == r) 
            return tree[v];
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum((v*2)+1, tm+1, tr, max(l, tm+1), r);
    }
    
    // Usage (1, 0, this->size, i, v) where i == index you want to update and v == new value
    void update(int v, int tl, int tr, int i, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (tm <= i) 
                update(v*2, tl, tm, i, new_val);
            else 
                update((v*2)+1, tm+1, tr, i, new_val);
            tree[v] = tree[v*2] + tree[(v*2)+1];
        }
    }

    void createTree(vector<int>& input, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = input[tl];
        } else {
            int tm = (tl + tr) / 2;
            createTree(input, v*2, tl, tm);
            createTree(input, (v*2)+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[(v*2)+1];
        }
        return;
    }

    SegmentTree(vector<int>& input) {
        if (input.size() == 0) 
            return;
        tree.resize(4*input.size());
        size = input.size()-1;
        createTree(input, 1, 0, size);
    }
};
~~~

Sparse table 
---
Used to perform range queries on immutable arrays. Most range queries can be calculated in O(log(n)), but minimum and maximum queries are O(1). It is extremely powerful for this reason.
~~~c++
class Sparse {
public:
    vector<vector<int> > st;
    vector<int> log;

    Sparse(vector<int>& in) {
        // Compute logarithm base 2
        log.resize(in.size()+1);
        log[1] = 0;
        for (int i = 2; i <= in.size(); i++)
            log[i] = log[i/2] + 1;
        // Create 2D array of [in.size()][K+1] where K = log2(in.size())
        st = vector<vector<int> >(in.size(), vector<int>(log[in.size()]+1));
        // Initialize
        for (int i = 0; i < in.size(); i++) 
            st[i][0] = in[i];
        // Compute queries
        for (int j = 1; j <= log[in.size()]; j++) 
            for (int i = 0; i + (1 << j) <= log[in.size()]; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }
    
    int get(int l, int r) {
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
~~~

Sliding window algorithm
---
An algorithm pattern that is ran on a 1D array to find a subarray that fits problem requirements. Uses two pointers to create a "window" in the array. Time: O(n).
~~~c++
int sliding_window(string s) {
    if (s.length() == 0) return 0;
    unordered_map<char, int> requirements;
    int counter = 0;
    for (char& c : s) {
        requirements[c]++;
        if (requirements[c] == 2) counter++;
    }
    int b = 0, e = 0, m = INT_MAX;
    while (e < s.length()) {
        requirements[s[e]]--;
        if (requirements[s[e]] == 1)
            counter--;
        while (b < s.length() && counter == 0) {
            m = min(m, e-(b-1));
            requirements[s[b]]++;
            if (requirements[s[b]] == 2) counter++;
            b++;
        }
        e++;
    }
    return m;
}
~~~ 

Improved analytical formula
---
Used to calculate the binomial coefficient `n` choose `k`. Time: O(k).
~~~c++
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
~~~

Pascal's triangle
---
Used to calculate a table of binomial coefficients. Can also be used relatively easily to calculate `n` choose `k` modulo `m` by `% m` to the nested for loop. Time: O(n<sup>2</sup>). 
~~~c++
int** pascals(int N) {
    int** C = new int*[N+1];
    for (int i = 0; i < N+1; i++)
        C[i] = new int[N+1];
    C[0][0] = 0;
    for (int n = 1; n <= N; n++) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; k++)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
    return C;
}
~~~

Polynomial rolling hash function
---
Used to calculate hashes of strings so that string equality can be determined in O(1). Time: O(n).
~~~c++
long long rolling_hash(string const& s) {
    // Pick prime near number of character possibilities. i.e. 26 letters = 31
    const int p = 31; 
    // Modulus
    const int m = 1e9 + 9;
    long long hash = 0;
    long long p_pow = 1;
    for (char& c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash;
}
~~~

Rabin-Karp algorithm
---
Used to find all patterns `s` in a text `t`. Time: O(|s| + |t|).
~~~c++
vector<int> rabin_karp(string const& s, string const& t) {
    // Same as polynomial rolling
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    // Calculate all p values
    vector<long long> p_pow(max(S, T));
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    // Calculate hashes at each spot inside of t
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    // Calculate h_s, the hash of size s inside of t
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    // Find occurences
    vector<int> o;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            o.push_back(i);
    }
    return o;
}
~~~

Modified Tarjan's algorithm
---
Used to find bridges. A bridge is an edge which makes the graph disconnected if removed. Time: O(V + E).
~~~c++
// Adjacency list of graph
vector<vector<int> > graph;    

vector<bool> visited;
vector<int> tin, low;
int timer;

// p = parent in this case.
void dfs(int v, int p = -1) {
    visited[v] = true;
    // tin is the "time in" of the node.
    tin[v] = low[v] = timer++;
    for (int to : graph[v]) {
        if (to == p) continue;
        // low keeps track of which strongly connected component
        // the node is a part of.
        else if (visited[to]) low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) ;
                // IT'S A BRIDGE, PROCESS 
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(graph.size(), false);
    tin.assign(graph.size(), -1);
    low.assign(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
        if (!visited[i]) dfs(i);
}
~~~

Kruskal's algorithm
---
Used to find the minimal spanning tree (MST). Time: O(E*log(V) + V<sup>2</sup>).
~~~c++
// An edge struct that has an operator overload for <
struct edge {
    int u, v, weight;
    bool operator<(edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<edge> edges;
int cost = 0;
vector<int> tree_id(n);
vector<edge> result;
for (int i = 0; i < n; i++) tree_id[i] = i;
sort(edges.begin(), edges.end());

// Greedy algorithm
for (edge e : edges) {
    // If edge connects two components that are not connected
    if (tree_id[e.u] != tree_id[e.v]) {
        cost += e.weight;
        result.push_back(e);
        // Connect trees (components)
        int old_id = tree_id[e.u], new_id = tree_id[e.v];
        for (int i = 0; i < n; i++)
            if (tree_id[i] == old_id)
                tree_id[i] = new_id;
    }
}
~~~

Booyer-Moore algorithm
---
Used to find if there is an item that takes up the majority of the array. Time: O(n).
~~~c++
int booyer_moore(vector<int>& A) {
    int candidate = 0;
    int count = 0;
    for (auto& item : A) {
        if (count == 0)
            candidate = item;
        if (candidate == item)
            count++;
        else
            count--;
    }
    count = 0;
    for (auto& item : A)
        if (item == candidate)
            count++;
    return (count > A.size() ? candidate : -1);
}
~~~
