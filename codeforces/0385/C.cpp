// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> primes;
vector<long long> counts;
const int d = 1e7 + 1;
 
void find_primes() {
    vector<bool> p(d+1, 1);
    for (int i = 2; i <= d; i++) {
        if (p[i]) {
            primes.push_back(i);
            for (int j = i; j <= d; j += i) {
                p[j] = 0;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());
 
    find_primes();
    counts.assign(d, 0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        counts[x]++;
    }
    
    vector<long long> f(d, 0);
    for (auto& p : primes) {
        for (int i = p; i < d; i += p) {
            f[p] += counts[i];
        }
    }
              
 
    // Transform to prefix array
    for (int i = 1; i < d; i++) {
        f[i] += f[i-1];
    }

    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        r = min(d-1, r);
        l = min(d-1, l);
        cout << f[r] - f[l-1] << endl;
    }
 
 
    return 0;
}
