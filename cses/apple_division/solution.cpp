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

ll ans = LLONG_MAX, master_sum = 0;
int n;
vector<ll> apples;

void build(int i, ll sum) {
    if (i >= n) {
        ans = min(ans, abs((master_sum - sum) - sum));
        return;
    }
    build(i+1, sum);
    build(i+1, sum + apples[i]);
    return;
}


void solve() {
    cin >> n;
    apples.resize(n);
    for (ll& x : apples) {
        cin >> x;
        master_sum += x;
    }

    build(0, 0);

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
