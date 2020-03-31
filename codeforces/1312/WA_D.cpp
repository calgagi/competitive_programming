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

const ll M = 998244353;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    ll n, m;
    cin >> n >> m;
    const int MAX_N = 2e5+1;

    vector<ll> factorial(MAX_N);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
    	factorial[i] = factorial[i - 1] * i % M;
    }


    if (n == 2) {
        cout << m << endl;
    } else {
        ll c = 1;
        for (ll i = 1; i <= n-3; i++) {
            c *= 2LL;
            c %= M;
        }
        ll ans = 0;
        for (int i = n-2; i <= m-1; i++) {
            ans = (ans + ((C(i, n-2)%M)*c))%M;
        }
        cout << ans << endl;
    }
        

    return 0;
}
