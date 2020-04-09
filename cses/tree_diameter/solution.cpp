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

vector<vector<int>> g;

ii dfs(int u, int par) {
    int l = 0, r = 0, ans = 1;
    for (auto& v : g[u]) {
        if (v == par) {
            continue;
        }
        ii p = dfs(v, u);
        if (l < p.s) {
            r = l;
            l = p.s;
        } else if (r < p.s) {
            r = p.s;
        }
        ans = max(p.f, ans);
    }
    ii a = {max(ans,l+r+1), max(l,r)+1};
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ii ans = dfs(0, -1);
    cout << max(ans.f, ans.s)-1 << endl;

    return 0;
}
