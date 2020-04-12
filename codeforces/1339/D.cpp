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
vector<bool> visited;
bool e = 0, o = 0;

void dfs(int c, bool x, int p) {
    if (p != -1 && g[c].size() == 1) {
        if (x) {
            e = 1;
        } else {
            o = 1;            
        }
    }
    for (auto& edge : g[c]) {
        if (edge != p) {
            dfs(edge, !x, c);
        }
    }
    return;
}

int dfs2(int c, int l, int p) {
    l--;
    if (l == 0) {
        return g[c].size() == 1;
    }     
    if (visited[c] == 1) {
        return 0;
    }
    if (g[c].size() != 1) {
        visited[c] = 1;
    }
    int ans = 0;
    for (auto& edge : g[c]) {
        if (edge != p) {
            ans += dfs2(edge, l, c);
        }
    }
    return ans;
}
        

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g.resize(n);
    visited.assign(n, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int fmn = -1, fmx = n-1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            dfs(i, 1, -1);
            if (o) {
                fmn = 3;
            } else {
                fmn = 1;
            }
            break;
        }
    }

    int next_to = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            next_to += dfs2(i, 3, -1);
        }
    }

    cout << fmn << " " << fmx-next_to << endl;

    return 0;
}
