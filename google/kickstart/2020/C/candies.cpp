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

    void build(vector<ll>& in) {
        a.clear();
        n = in.size();
        a.assign(n, 0);
        for (int i = 0; i < n; i++) {
            upd(i, in[i]);
        }
        return;
    }

    ll get(int i) {
        ll ans = 0;
        for (; i >= 0; i = (i & (i+1)) - 1) {
            ans += a[i];
        }
        return ans;
    }

    ll sum(int l, int r) {
        return get(r) - get(l-1);
    }
    
    void upd(int i, ll u) {
        for (; i < n; i = i | (i+1)) {
            a[i] += u;
        }
    }
};

fenwick fE, fO, fEM, fOM;
vector<ll> a;

void update() {
    int i, v;
    cin >> i >> v;

    ll old = a[i];
    ll odd = (i & 1) ? 1 : -1;
    ll even = (i & 1) ? -1 : 1;
    fE.upd(i, odd*old + (even*v));
    fO.upd(i, even*old + (odd*v));
    fEM.upd(i, (odd*old + (even*v))*i);
    fOM.upd(i, (even*old + (odd*v))*i);

    a[i] = v;

    return;
}

ll query() {
    int l, r;
    cin >> l >> r;

    ll ans = 0;
    if ((l & 1)) {
        ans = fOM.sum(l, r) - (l-1)*fO.sum(l, r);
    } else {
        ans = fEM.sum(l, r) - (l-1)*fE.sum(l, r);
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (ll& x : a) {
        cin >> x;
    }

    a.insert(a.begin(), 0);
    vector<ll> aE = a, aO = a, aEM = a, aOM = a; 
    for (ll i = 1; i < n+1; i++) {
        ll odd = (i & 1) ? 1 : -1, even = (i & 1) ? -1 : 1;
        aE[i] *= even;
        aO[i] *= odd; 
        aEM[i] *= even * i;
        aOM[i] *= odd * i;
    }

    fE.build(aE);
    fO.build(aO);
    fEM.build(aEM);
    fOM.build(aOM);

    ll ans = 0;

    for (int i = 0; i < q; i++) {
        char x;
        cin >> x;
        if (x == 'Q') {
            ans += query();
        } else {
            update();
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
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
