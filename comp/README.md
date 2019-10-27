# comp
Programming competitions I've competed in or did for practice.

Here's a list of cool algorithms I've discovered.

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

Least common multiple
---
Used to find the least common multiple.
~~~c++
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
~~~

Triangle Inequality Theorem
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
~~c++
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
                q.push({-distance[b], b});
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
