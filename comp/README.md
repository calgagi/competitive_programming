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
