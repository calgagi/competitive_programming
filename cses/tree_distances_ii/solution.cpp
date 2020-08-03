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
ll subtree_size[MAX_N], subtree_weight[MAX_N], ans[MAX_N];

void dfs(int cur, int parent) {
    subtree_size[cur] = 1;
    subtree_weight[cur] = 0;
    for (int& edge : tree[cur]) {
        if (edge != parent) {
            dfs(edge, cur);
            subtree_size[cur] += subtree_size[edge];
            subtree_weight[cur] += subtree_size[edge] + subtree_weight[edge];
        }
    }

    return;
}

void dfs2(int cur, int parent, ll above_weight) {
    ans[cur] = above_weight + subtree_weight[cur];
    // above_weight + amount to go down 1 from (above + root)
    ll new_weight = above_weight + (n - subtree_size[cur]) + 1;

    for (int& edge : tree[cur]) {
        if (edge != parent) {
            // += weight of subtree and distance to go up 1 and down 1
            new_weight += (2LL * subtree_size[edge]) + subtree_weight[edge];
        }
    }

    for (int& edge : tree[cur]) {
        if (edge != parent) {
            dfs2(edge, cur, new_weight - (2LL * subtree_size[edge]) - subtree_weight[edge]);
        }
    }

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

    dfs(0, -1);
    ans[0] = subtree_weight[0];

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
