// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

long long m;

long long mult(long long a, long long b) {
    return (a * b) % m;
}

long long add(long long a, long long b) {
    return (a + b) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    long long n; cin >> n >> m;

    vector<long long> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mult(i, fact[i-1]);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = add(ans, mult((n-(i-1)), mult(fact[i], fact[n-(i-1)])));
    }
    cout << ans << endl;

    return 0;
}
