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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<ll> bit(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j = j | (j+1)) {
            bit[j] += a[i];
        }
    }

    while (q--) {
        int t, k, u;
        cin >> t >> k >> u;
        if (t == 1) {
            k--;
            ll s = a[k];
            a[k] = u;
            for (int j = k; j < n; j = j | (j+1)) {
                bit[j] += u-s;
            }
        } else if (t == 2) {
            u--; 
            ll l = 0, r = 0;
            k-=2;
            for (; k >= 0; k = (k & (k+1)) - 1) {
                l += bit[k];
            } 
            for (; u >= 0; u = (u & (u+1)) - 1) {
                r += bit[u];
            }
            cout << r-l << endl;
        }
    }

    return 0;
}
