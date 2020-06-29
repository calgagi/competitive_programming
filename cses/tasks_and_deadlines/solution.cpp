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
    int n;
    cin >> n;
    vector<ii> tasks(n);
    for (ii& x : tasks) {
        cin >> x.f >> x.s;
    }

    sort(tasks.begin(), tasks.end(), [&](const ii& a, const ii& b) {
        return a.f < b.f;
    });

    ll time = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        time += tasks[i].f;
        ans += tasks[i].s - time;
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
