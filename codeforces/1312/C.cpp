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
    ll n, k;
    cin >> n >> k;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        q.push(x);
    }
   
    ll MAX = q.top();
    vector<ll> s;
    ll x = 1;
    while (x <= MAX) {
        s.push_back(x);
        x *= k;
    }
    int m = s.size();
    for (int i = m-1; i >= 0; i--) {
        ll d = q.top();
        q.pop();
        d -= (d < s[i] ? 0 : s[i]);
        q.push(d);
    }  

    while (!q.empty()) {
        if (q.top() != 0) {
            cout << "NO" << endl;
            return;
        }
        q.pop();
    } 
    
    cout << "YES" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
