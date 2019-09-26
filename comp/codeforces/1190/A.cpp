// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll p, r = 0, i = 0;
    while (i < m) {
        p = ((a[i] - i - 1) / k+1)*k + i;
        ll j = i;
        while (j < m && a[j] <= p) j++;
        r++;
        i = j;
    }

        
    cout << r << endl;

    return 0;
}
