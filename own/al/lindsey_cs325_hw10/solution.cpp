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

unordered_map<char,unordered_set<char>> match;

void solve1(string rna) {
    const int n = rna.length();
    vector<vector<int>> dp(n, vector<int>(n, 0)); 

    for (int L = n-2; L >= 0; L--) {
        for (int R = L+1; R < n; R++) {
            if (match[rna[L]].count(rna[R])) {
                dp[L][R] = dp[L+1][R-1]+1+(R<n-1?dp[R+1][n-1]:0);
            } else {
                dp[L][R] = max(dp[L+1][R]+(R<n-1?dp[R+1][n-1]:0), dp[L][R-1]+(R<n?dp[R][n-1]:0));
            }
        }
    }
    for (auto& v : dp) {
        for (auto& x : v) cout << x << " ";
        cout << endl;
    }
    
    cout << dp[0][n-1] << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    
    match['U'].insert('A');
    match['A'].insert('U');
    match['G'].insert('C');
    match['G'].insert('U');
    match['C'].insert('G');
    match['U'].insert('G');
	
    vector<string> tests = {"GCACG", "ACAGU", "UUCAGGA", "AGGCAUCAAACCCUGCAUGGGAGCACCGCCACUGGCGAUUUUGGUA", "CAUCGGGGUCUGAGAUGGCCAUGAAGGGCACGUACUGUUU"};
    forn(i, tests.size()) {
        solve1(tests[i]); 
    }
    

    return 0;
}
