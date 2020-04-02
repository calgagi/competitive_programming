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

vector<ll> fenwick;
vector<ll> nums;

void update(int i, ll u) {
    int n = fenwick.size();
    for (; i < n; i = (i | (i+1))) {
        fenwick[i] += u;
    }
    return;
} 

ll sum(int i) {
    int save = i;
    ll res = 0;
    for (; i >= 0; i = (i & (i+1))-1) {
        res += fenwick[i];
    }
    return nums[save] + res;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, q;
    cin >> n >> q;
    fenwick.assign(n, 0);
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            a--, b--;
            update(a, u);
            update(b+1, -u);
        } else {
            int k;
            cin >> k;
            k--;
            cout << sum(k) << endl;
        }
    }
        

    return 0;
}
