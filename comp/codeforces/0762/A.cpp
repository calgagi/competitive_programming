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

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll> > f;
    for (ll i = 1; i < sqrt(n); i++) {
        if (n % i == 0) {
            f.push_back({i, n / i});
        }
    }
    if (floor(sqrt(n)) == sqrt(n)) {
        f.push_back({sqrt(n), -1});
    }
    int j = f.size()-1;
    if (f[j].second == -1) j--;
    for (int i = 0; i < j; i++, j--) {
        swap(f[i].second, f[j].second);
    }
    if (k > 2*f.size())
        cout << -1 << endl;
    else if (k > f.size()) {
        k -= f.size();
        cout << f[k-1].second << endl;
    } else {
        cout << f[k-1].first << endl;
    } 

    return 0;
}
