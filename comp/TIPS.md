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
    // ...
}
~~~

Sliding window
---

