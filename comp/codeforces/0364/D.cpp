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
    
    unordered_map<ll,int> freq;
    int n; cin >> n;
    vector<ll> nums(n);
    forn(i, n) cin >> nums[i];
    ll i;
    forn(j, 20) {
        ll x = nums[rand()%n];
        for(i = 1; i <= sqrt(x); i++) {
            if(x % i == 0) {
                freq[i]++;
                if(i*i != x) freq[x/i]++;
            }
        }
    }
    ll res = 1;
    for(auto it = freq.begin(); it != freq.end(); it++)
        if (it->second >= (n+1/2))
            res = max(it->first,res);
    cout << res << endl;

    return 0;
}
