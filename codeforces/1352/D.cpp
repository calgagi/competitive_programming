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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = n-1;
    int moves = 0;
    ll size_a = 0, size_b = 0, prev = 0;
    while (i <= j) {
        // alice
        ll cur = 0;
        for (; cur <= prev && i <= j; i++) {
            cur += a[i];
        } 
        size_a += cur;
        moves++;
        prev = cur;
        cur = 0;
        if (i > j) {
            break;
        }
        for (; cur <= prev && i <= j; j--) {
            cur += a[j];
        }
        size_b += cur;
        prev = cur;
        moves++;
    }

    cout << moves << " " << size_a << " " << size_b << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
