/*
ID: calgagi1
LANG: C++
TASK: humble
*/
/* 
 * author: calgagi
 *         Calvin Gagliano
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

void solve() {
    int k, n;
    cin >> k >> n;
    vector<ll> s(k);

    set<ll> q;

    for (int i = 0; i < k; i++) {
        cin >> s[i];
        q.insert(s[i]);
    }

    ll ans;
    for (auto it = q.begin(); it != q.end(); it++) {
        ans = *it;
        for (ll& x : s) {
            if (ans*x >= INT_MAX || (q.size() >= n && ans*x >= *prev(q.end()))) {
                break;
            }
            q.insert(ans*x); 
        }
        while (!q.empty() && q.size() > n) {
            q.erase(prev(q.end()));
        }    
    }
    
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("humble.in", "r", stdin), *OUT = freopen("humble.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
