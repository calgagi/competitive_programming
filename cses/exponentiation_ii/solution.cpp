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

const int M = 1e9+7;

ll mpow(ll a, ll b, ll m) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans*a) % m;
        }
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    //cout << x << endl;
    cout << mpow(a,mpow(b,c,M-1),M) << endl; 
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
