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
    ll n;
    cin >> n;

    int ans = 0;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            int counter = 1, j = 0;
            while (n % i == 0) {       
                n /= i;
                j++;
                if (j == counter) {
                    counter++;
                    j = 0;
                    ans++;
                }
            }
        }
    }
         
    bool prime = n != 1;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            prime = 0;
        }
    }

    if (prime) {
        ans++;
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
