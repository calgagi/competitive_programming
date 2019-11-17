// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    
    int n; cin >> n;
    vector<ll> nums(n);
    forn(i, n) cin >> nums[i];
    ll ans = 0;
    unordered_map<ll,int> freq;
    unordered_map<ll,bool> seen;
    forn(j, 50) {
        ll x = rand()%n;
        if(seen[x]) continue; 
        seen[x] = true;
        x = nums[x];
        for(ll i = 1; i < sqrt(x)+1; i++) {
            if (x % i == 0) {
                freq[i]++;
                if (i*i != x)
                    freq[x/i]++;
            }
        }
    }
    for(auto it = freq.begin(); it != freq.end(); it++)
        if (it->second >= min((n+1)/2, 25))
            ans = max(it->first,ans);

    cout << ans << endl;

    return 0;
}
