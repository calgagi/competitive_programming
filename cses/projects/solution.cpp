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
    vector<ar<ll,3>> projects(n);
    for (ar<ll,3>& project : projects) {
        cin >> project[0] >> project[1] >> project[2];
    } 
    
    sort(projects.begin(), projects.end());

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0, 0});

    ll max_val = 0;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.top().f < projects[i][0]) {
            max_val = max(max_val, q.top().s);
            q.pop();
        }
        q.push({projects[i][1], max_val + projects[i][2]});
    }
            
    while (!q.empty()) {
        max_val = max(q.top().s, max_val);
        q.pop();
    }

    cout << max_val << endl;

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
