/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long long, long long>
#define ar array
#define f first
#define s second

struct fenwick {
    map<int,int> cnt;
    const int MAX_SAL = 1e9;

    void build(vector<int>& s) {
        for (int i = 0; i < (int) s.size(); i++) {
            update(s[i], 1);
        }
        return;
    }

    void update(int i, int diff) {
        for (; i <= MAX_SAL; i = (i | (i + 1))) {
            cnt[i] += diff;
        }
        return;
    }

    int get(int i) {
        int ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans += cnt[i];
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> sal(n);
    for (int i = 0; i < n; i++) {
        cin >> sal[i];
    }

    fenwick f;
    f.build(sal);

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if (type == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            f.update(sal[k], -1);
            sal[k] = x;
            f.update(sal[k], 1);
        } 
        else if (type == '?') {
            int a, b;
            cin >> a >> b;
            cout << f.get(b) - f.get(a-1) << endl;
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
