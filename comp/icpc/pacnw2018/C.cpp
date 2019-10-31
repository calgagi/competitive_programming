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

ll MOD = 998244353; 

int add(long a, long b) {
    return (a + b) % MOD;
}

int mult(long a, long b) {
    return (a * 1LL * b) % MOD;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int,int> m;
    int n, k; cin >> n >> k;
    vector<int> b(n);
    int j = 0;
    forn(i, n) {
        int a; cin >> a;
        if (m.find(a) == m.end())
            m[a] = j++;
        b[m[a]]++;
    }
    ll total = 1;
    if (j < k) {
        cout << "0" << endl;
        return;
    }
    ll res = 0;
    
        
         
    return 0;
}
