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

struct fenwick {
    vector<ll> a;
    int n;

    void build(ll s, int n) {
        this->n = n;
        a.assign(n, 0);
        update(0, s);
        return;
    }

    ll sum(int i) {
        ll ans = 0;
        for (; i >= 0; i = (i & (i+1)) - 1) {
            ans += a[i];
        }
        return ans;
    }

    void update(int i, ll d) {
        for (; i < n; i = i | (i+1)) {
            a[i] += d;
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m, c;
    cin >> n >> m >> c;

    fenwick f;
    f.build(c, n);

    while (m--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int i;
            cin >> i;
            i--;
            cout << f.sum(i) << endl;
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            f.update(l, v);
            f.update(r+1, -v);
        }
    }


    return 0;
}
