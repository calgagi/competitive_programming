/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long, long>
#define ar array
#define f first
#define s second

long lcm(long a, long b) {
    return a*b / __gcd(a,b);
}

void solve() {
    long n;
    cin >> n;
    
    if (!(n & 1)) {
        cout << n/2 << " " << n/2 << endl;
    } else {
        ii ans = {1, n-1}; 
        for (long i = 1; i*i <= n; i++) {
            if (lcm(i, n-i) < lcm(ans.f, ans.s)) {
                ans = {i, n-i};
            }
            if (i != 1LL && lcm(n/i, n - n/i) < lcm(ans.f, ans.s)) {
                ans = {n/i, n - n/i};
            }
        }
        cout << ans.f << " " << ans.s << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
