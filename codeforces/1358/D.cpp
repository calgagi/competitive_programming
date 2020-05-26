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
    
    ll n, x;
    cin >> n >> x;
    vector<ll> d(n);
    for (ll& z : d) {
        cin >> z;
    }

    d.insert(d.end(), d.begin(), d.end());

    ll cur = 0, curS = 0;
    ll ans = 0;
    vector<ll> val(d.size(), 0), days_subtracted(d.size(), 0);
    for (int i = 0; i < 2*n; i++) {
        val[i] = (d[i]*(d[i]+1))/2;
    }

    for (int b = 0, e = 0; e < (int) d.size(); e++) {
        curS += val[e];
        cur += d[e];
        while (cur-(d[b]-days_subtracted[b]) > x) {
            curS -= val[b];
            cur -= (d[b]-days_subtracted[b]);
            b++;
        }
        if (cur > x) {
            ll days_over = cur-x;
            cur = x;
            days_subtracted[b] += days_over;
            curS -= val[b];
            ll value = (d[b]*(d[b]+1))/2 - (days_subtracted[b]*(days_subtracted[b]+1))/2;
            val[b] = value; 
            curS += val[b];
        }
        ans = max(ans, curS);
    }

    cout << ans << endl;


    return 0;
}
