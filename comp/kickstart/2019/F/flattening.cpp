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
	
    int T; cin >> T;
    forn(t, T) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        unordered_map<int,int> m;
        int maximum = 0;
        forn(a, N) { 
            cin >> A[a];
            m[A[a]]++;
            if (m[A[a]] > m[maximum])
                maximum = A[a];
        }
        vector<vector<int> > dp(K+1, vector<int>(N, 0));
        for(int i = 0, j = 0; i < N; i++)
            if (A[i] != maximum)
                dp[0][i] = ++j;
        fore(i, 1, K+1) {
            fore(j, 1, N) {
                if (
            
            
            
            
            

    return 0;
}
