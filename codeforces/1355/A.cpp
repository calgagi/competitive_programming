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
    
    int t;
    cin >> t;
    while (t--) {
        ll a, k;
        cin >> a >> k;

        for (int i = 1; i < k; i++) {
            ll prev = a;
            ll mx = 0, mn = 9, x = a;
            while (x) {
                mx = max(mx, x % 10);
                mn = min(mn, x % 10);
                x /= 10;
            }
            a = prev + mx*mn;
            if (a == prev) {
                break;
            }
        }

        cout << a << endl;
    }

    return 0;
}
