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

vector<int> tree, val, pos;
int n, ans;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = 1;
    } else {
        int tm = tl + (tr - tl) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
    return;
}

void update(int v, int tl, int tr, int x) {
    if (tl == tr) {
        tree[v] = 0;
        ans = tl;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (x <= tree[2*v]) {
            update(v*2, tl, tm, x);
        } else {
            x -= tree[2*v];
            update(v*2+1, tm+1, tr, x);
        } 
        tree[v] = tree[v*2] + tree[v*2+1];
    }
    return;
}

void solve() {
    cin >> n;
    val.resize(n);
    pos.resize(n);
    tree.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    build(1, 0, n-1);
        
    for (int i = 0; i < n; i++) {
        update(1, 0, n-1, pos[i]);
        cout << val[ans] << " ";
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
