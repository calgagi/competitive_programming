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

const int B = 20;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    vector<ll> ans(n, 0);
    for (int i = 0; i < B; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            count += ((1 << i) & a[j]) ? 1 : 0;
        }
        for (int j = 0; j < count; j++) {
            ans[j] |= (1 << i);
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i] * ans[i];
    }

    cout << sum << endl;

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
