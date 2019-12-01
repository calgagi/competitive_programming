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


int mult(ll a, ll b) {
    return (a * 1LL * b) % 11092019;
}

int add(ll a, ll b){
    return (a + b) % 11092019;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    string s; cin >> s;
    int n = s.length();
    unordered_map<char,int> seen;
    int total = 0;
    
    vector<int> dp(n+1);
    dp[0] = 1;
    fore(i, 1, n+1) {
        seen[s[i-1]]++;
        dp[i] = add(dp[i-1], dp[i-1] / seen[s[i-1]]);
    }
    cout << dp[n] << endl;
        

    return 0;
}
