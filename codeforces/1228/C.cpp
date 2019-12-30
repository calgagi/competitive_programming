// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;
long long MOD = 1e9 + 7; 

void sieve(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0)
            primes.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x > 1)
        primes.push_back(x);
}

long long mult(long long a, long long b) {
    return (a * 1LL * b) % MOD;
}


long long mpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    long long x, n; cin >> x >> n;

    sieve(x);
    
    long long ans = 1;
    for (auto& p : primes) {
        long long factor = p, power = 0;
        while (factor <= n) {
            power += n / factor;
            if (factor > LLONG_MAX / p) break;
            factor *= p;
        }

        ans = mult(ans, mpow(p, power));
    }
            
    cout << ans << endl;
        

    return 0;
}
