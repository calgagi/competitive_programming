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

vector<int> hotels, query;
vector<int> tree;
int n, m, ans = -1;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = hotels[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
    return;
}

void build() {
    n = hotels.size();
    tree.resize(4*n);
    build(1, 0, n-1);
    return;
}

void update(int v, int tl, int tr, int q) {
    if (tl == tr) {
        ans = tl;
        tree[v] -= q;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (q <= tree[2*v]) {
            update(2*v, tl, tm, q);
        } else {
            update(2*v+1, tm+1, tr, q);
        }
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
    return;
}

void solve() {
    cin >> n >> m;
    hotels.resize(n);
    query.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }

    build();
    
    for (int i = 0; i < m; i++) {
        if (tree[1] < query[i]) {
            cout << 0 << " ";
        } else {
            update(1, 0, n-1, query[i]);
            cout << ans+1 << " ";
        }
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
