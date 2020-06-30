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

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    vector<ll> pre(N);
    for (int i = 0; i < N; i++) {
        pre[i] = (i ? pre[i-1] : 0LL) + A[i];
        pre[i] %= N;
        if (pre[i] < 0) {
            pre[i] += N;
        }
    }

    ll ans = 0;
    map<ll,ll> seen;
    seen[0] = 1;

    for (int i = 0; i < N; i++) {
        int inverse = pre[i] - N;
        if (inverse < 0) {
            inverse += N;
        }
        ans += seen[inverse];
        seen[pre[i]]++;
    }

    cout << ans << endl;
            
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
