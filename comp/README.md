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
