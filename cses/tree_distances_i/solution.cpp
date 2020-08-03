/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

const int MAX_N = 2e5;
int n;
vector<int> tree[MAX_N];
int ans[MAX_N], depth[MAX_N];
bool visited[MAX_N];

void dfs2(int cur, int par, int above) {
    if (par != -1) {
        ans[cur] = max(depth[cur], above);
    }
    pair<int,int> new_above = {above + 1, -1};
    for (int& edge : tree[cur]) {
        if (par != edge && new_above.first < depth[edge] + 2) {
            new_above = {depth[edge] + 2, edge};
        }
    }
    for (int& edge : tree[cur]) {
        if (par != edge && edge != new_above.second) {
            dfs2(edge, cur, new_above.first);
        } else if (edge == new_above.second) {
            int new_above2 = above + 1;
            for (int& edge2 : tree[cur]) {
                if (edge2 != par && edge2 != new_above.second && new_above2 < depth[edge2] + 2) {
                    new_above2 = depth[edge2] + 2;
                }
            }
            dfs2(edge, cur, new_above2);
        }
    }
    return;
}

void dfs(int cur, int par) {
    int ans = 0;
    depth[cur] = 0;
    for (int& edge : tree[cur]) {
        if (edge != par) {
            dfs(edge, cur);
            ans = max(depth[edge] + 1, ans);
        }
    }
    depth[cur] = ans;
    return;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    memset(depth, 255, sizeof(depth));

    dfs(0, -1);
    ans[0] = depth[0];
    
    dfs2(0, -1, 0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

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
