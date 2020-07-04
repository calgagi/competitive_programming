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

class fenwick {
public:
    vector<ll> A;
    int N;

    void build(vector<ll>& a) {
        N = a.size();
        A.assign(N, 0);
        for (int i = 0; i < N; i++) {
            update(i, a[i]);
        }
    }
    
    void update(int i, ll diff) {
        for (; i < N; i = (i | (i + 1))) {
            A[i] += diff;
        }
        return;
    }

    ll sum(int i) {
        ll ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans += A[i];
        }
        return ans;
    }

    ll sum(int a, int b) {
        return sum(b) - sum(a-1);
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (ll& a : A) {
        cin >> a;
    }

    fenwick F;
    F.build(A);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll k, u;
            cin >> k >> u;
            k--;
            F.update(k, u - A[k]);
            A[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << F.sum(a, b) << endl;
        }
    }
        

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
