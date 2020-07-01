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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for (int& x : X) {
        cin >> x;
    }

    vector<ll> prefix(N+1);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + X[i-1];
    }

    multiset<ll> range;

    ll ans = LLONG_MIN;
    for (int i = A; i <= N; i++) {
        range.insert(prefix[i-A]);
        if (i-B-1 >= 0) {
            auto it = range.find(prefix[i-B-1]);
            range.erase(it);
        }
        ans = max(ans, prefix[i] - *range.begin());
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
