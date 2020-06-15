/*
ID: calgagi1
LANG: C++
TASK: fact4
*/
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

    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0) {
            ans /= 10;
        }
        ans %= 10000000;
        //cerr << i << " " << ans << endl;
    }

    cout << ans % 10 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("fact4.in", "r", stdin), *OUT = freopen("fact4.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
