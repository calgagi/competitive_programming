# Tips and Tricks
Useful tips that aren't straight algorithms.

Coordinate hashmap
---
Hashmap in C++ that uses a std::pair as a key.
~~~c++
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
unordered_map<pair<int,int>, int, pair_hash> map;
~~~

No number of lines
---
Test if there's no more stdin available.
~~~c++
while (true) {
    cin >> a >> b >> c;
    if (cin.fail()) break;
    // Rest of your code...
}
~~~

Min stack modification
---
Get the minimum element in a stack in O(1) time.
~~~c++
stack<pair<int,int> > s;

// Insertion
int new_min = s.empty() ? new_elem : min(new_elem, s.top().second);
s.push({new_elem, new_min});

// Get min
int min_in_stack = s.top().second;

// Get element
int element = s.top().first;
~~~

Min queue modification
---
Get the minimum element in a queue in O(1) time by implementing the queue with 2 stacks.

Method 1: Use deque.
~~~c++
deque<int> q;

// Find min
int mininum = q.front();

// Insert
while (!q.empty() && q.back() > new_elem)
    q.pop_back();
q.push_back(new_elem);

// Removal
if (!q.empty() && q.front() == removal)
    q.pop_front();
~~~

Method 2: Use two stacks.
~~~c++
stack<pair<int,int> > s1, s2;

// Find min
if (s1.empty() || s2.empty())
    minimum = s1.empty() ? s2.top().second : s1.top().second;
else
    minimum = min(s1.top().second, s2.top().second);

// Insertion
minimum = s1.empty() ? new_elem : min(s1.top().second, new_elem));
s1.push({new_elem, minimum});

// Removal
if (s2.empty()) {
    while (!s1.empty()) {
        int elem = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? elem : min(elem, s2.top().second);
        s2.push({elem, minimum});
    }
}
int remove = s2.top().first;
s2.pop();
~~~ 

Bezout's identity
---
For non-zero integers `a` and `b`, let `d` be equal to `gcd(a, b)`. Then, there exists integers `x` and `y` such that `ax + by = d`.

Binomial coefficients
---
Calculate the number of ways to select a set of `k` elements from `n` different elements without taking into account the order of the elements (number of unordered sets). Equivalent to `n` choose `k` = (`n`!) / (`k`! (`n`-`k`)!).
![Properties](https://ibb.co/mqnC6wm)

Stars and bars
---
The number of ways to put `n` identical objects into `k` boxes is `n + k - 1` choose `n`. Combination can be solved using binomial coefficient algorithm.
