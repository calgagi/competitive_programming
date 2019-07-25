// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Calculate primes using Sieve of Eratosthenes
    int r, l;
    cin >> l >> r;
    bool *prime = new bool[r+1];
    memset(prime, 1, sizeof(bool)*(r+1));
    prime[0] = prime[1] = false;
    int s = sqrt(r);
    vector<int> primes;
    for (int i = 2; i <= r; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (int k = i*i; k <= r; k += i)
                prime[k] = false;
        }
    }

    vector<int> counts(primes.size(), 0);
    int x = -1, v = 0;
    for ( ; l <= r; l++) {
        int t = 0;
        while (l % primes[t]) t++;
        counts[t]++;
        if (x < counts[t]) { 
            x = counts[t];
            v = primes[t]; 
        }
    }
    cout << v << endl;
    return 0;
}
