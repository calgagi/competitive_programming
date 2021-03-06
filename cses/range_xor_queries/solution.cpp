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
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i-1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (a[r]^a[l-1]) << endl;
    }

    return 0;
}
