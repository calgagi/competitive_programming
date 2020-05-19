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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int& x : a) {
        cin >> x;
        sum += abs(x);
    }

    ll ans = 0;
    int tot = 0;
    vector<int> seen(2*sum+1, 0);
    for (int i = 0; i < n; i++) {
        seen[tot + sum]++;
        tot += a[i];
        for (int j = 0; j*j <= sum; j++) {
            int q = tot - j*j + sum;
            if (q < 0) {
                break;
            }
            ans += seen[q];
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
