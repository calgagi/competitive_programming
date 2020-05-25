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

const int D = 1e9+7;

struct comp {
    bool operator()(const ar<ll,3>& a, const ar<ll,3>& b) {
        return a[0] > b[0];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll shift = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (!i && !j) {
                shift = a[i][j];
            }
            a[i][j] -= shift;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    priority_queue<ar<ll,3>, vector<ar<ll,3>>, comp> q;
    q.push({0, 0, 0});
    ll ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    while (!q.empty()) {
        ar<ll,3> x = q.top();
        q.pop();
        if (visited[x[1]][x[2]]) {
            continue; 
        }
        visited[x[1]][x[2]] = 1;
        
        if (x[1] == n-1 && x[2] == m-1) {
            ans = x[0];
            break;
        }
        ll z = x[1]+x[2]+1;
        if (x[1] < n-1) {
            q.push({x[0] + abs(z-a[x[1]+1][x[2]]), x[1]+1, x[2]});
        }
        if (x[2] < m-1) {
            q.push({x[0] + abs(z-a[x[1]][x[2]+1]), x[1], x[2]+1});
        }
    }    

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
