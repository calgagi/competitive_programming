// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;

long long mult(long long a, long long b) {
    return (a * b) % MOD;
}

long long add(long long a, long long b) {
    return (a + b) % MOD;
}

void solve() {
    long long x; cin >> x;
    string s; cin >> s;

    long long ans = (long long) s.length();
    for (long long i = 1; i <= x; i++) {
        ans = add(ans, mult(s[i-1]-'0'-1, ans-i)); 
        if ((long long) s.length() < x) {
            string t = s.substr(i);
            for (int j = 0; j < s[i-1]-'0'-1 && (long long) s.length() < x; j++)
                s += t;
        }
    }
    cout << (ans % MOD + MOD) % MOD << endl;
}
        
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
