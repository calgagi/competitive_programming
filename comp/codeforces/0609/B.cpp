// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n, m; cin >> n >> m;
    vector<int> c(m, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        c[t-1]++;
    }
    int res = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int j = i+1; j < c.size(); j++) {
            res += c[i] * c[j];
        }
    }
    cout << res << endl;
    return 0;
}
