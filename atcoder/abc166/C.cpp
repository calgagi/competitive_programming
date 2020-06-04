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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    
    vector<int> obs(n);
    for (int i = 0; i < n; i++) {
        cin >> obs[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool high = 1;
        for (auto& edge : adj[i]) {
            if (obs[edge] >= obs[i]) {
                high = 0;
                break;
            }
        }
        ans += high;
    }

    cout << ans << endl; 

    return 0;
}
