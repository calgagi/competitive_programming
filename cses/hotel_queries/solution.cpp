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

class Segtree {
public:
    vector<int> tree;
    int n;

    Segtree(vector<int> a) {
        n = a.size();
        tree.resize(4*n);
        build(a, 1, 0, n-1);
        return;
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
        return;
    }

    void update(int v, int tl, int tr, int i, int k) {
        if (tl == tr) {
            tree[v] = k;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (i <= tm) {
                update(2*v, tl, tm, i, k);
            } else {
                update(2*v+1, tm+1, tr, i, k);
            }
            tree[v] = max(tree[2*v], tree[2*v+1]);
        }
        return;
    }

    int get_max(int v, int tl, int tr, int left, int right) {
        if (left > right) {
            return 0;
        } else if (left == tl && right == tr) {
            return tree[v];
        }
        int tm = tl + (tr - tl) / 2;
        return max(
            get_max(2*v, tl, tm, left, min(tm, right)),
            get_max(2*v+1, tm+1, tr, max(left, tm+1), right)
        );
    } 
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> hotels(n);
    for (int& hotel : hotels) {
        cin >> hotel;
    }
    
    Segtree seg(hotels);
    
    while (m--) {
        int q;
        cin >> q;

        int left = 0, right = n-1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mx = seg.get_max(1, 0, n-1, 0, mid);
            if (mx >= q) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        cout << ans+1 << " ";
        if (ans != -1) {
            hotels[ans] -= q;
            seg.update(1, 0, n-1, ans, hotels[ans]);
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
