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
    ll n;
    cin >> n;

    vector<ll> health(n), damage(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i] >> damage[i];
    }

    ll prev_damage = damage[n-1], min_damage = LLONG_MAX, start = 0;
    for (int i = 0; i < n; i++) { 
        if (min_damage > health[i] - max(health[i] - prev_damage, 0LL)) {
            min_damage = health[i] - max(health[i] - prev_damage, 0LL);
            start = i;
        }
        prev_damage = damage[i];
    }

    ll ans = health[start];
    prev_damage = damage[start];
    for (int i = (start+1) % n; i != start; i = (i+1) % n) {
        health[i] = max(health[i]-prev_damage, 0LL);
        ans += health[i];
        prev_damage = damage[i];
    }

    cout << ans << endl;

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
