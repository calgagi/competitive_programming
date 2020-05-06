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

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        unordered_map<string, int> n;
        vector<string> nn(N);
        vector<tuple<ll,ll,ll>> l(N);
        for (int j = 0; j < N; j++) {
            string s;
            ll x, y, z;
            cin >> s >> x >> y >> z;
            n[s] = j;
            nn[j] = s;
            l[j] = make_tuple(x, y, z);
        }
        vector<vector<ll> > g(N, vector<ll>(N, 0));
        for (int j = 0; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                ll x = 0;
                x += pow(get<0>(l[k])-get<0>(l[j]), 2);
                x += pow(get<1>(l[k])-get<1>(l[j]), 2);
                x += pow(get<2>(l[k])-get<2>(l[j]), 2);
                x = sqrt(x);
                g[j][k] = x;
                g[k][j] = x;
            }
        }
        int W; cin >> W;
        for (int j = 0; j < W; j++) {
            string s, d;
            cin >> s >> d;
            g[n[s]][n[d]] = 0;
        } 
        // Graph made, now Floyd-Warshall
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int m = 0; m < N; m++) {
                    g[k][m] = min(g[k][m], g[k][j] + g[j][m]);
                }
            }
        }
        // Now, print
        cout << "Case " << i+1 << ":" << endl;
        int Q; cin >> Q;
        for (int j = 0; j < Q; j++) {
            string s, d;
            cin >> s >> d;
            cout << "The distance from " << s << " to " << d << " is ";
            cout << g[n[s]][n[d]] << " parsecs." << endl;
        }
    } 


    return 0;
}
