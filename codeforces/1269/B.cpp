// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n, m; cin >> n >> m;
    vector<long> a(n), b(n);
    for (int i = 0; i < n; i++)  cin >> a[i];
    for (int i = 0; i < n; i++)  cin >> b[i];
    sort(b.begin(), b.end());


    vector<long> poss;
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        int d = (b[0] - a[i]);
        if (d >= m) d -= m;
        else if (d < 0) d += m;
        if (seen.find(d) == seen.end()) {
            poss.push_back(d);
            seen.insert(d);
        }
    }

    sort(poss.begin(), poss.end());

    for (auto& p : poss) {
        vector<long> c = a;
        for (int i = 0; i < n; i++) {
            c[i] += p;
            if (c[i] >= m) c[i] -= m;
        }
        sort(c.begin(), c.end());
        int i = 0;
        while (i < n) {
            if (c[i] != b[i]) break;
            i++;
        }
        if (i == n) {
            cout << p << endl;
            break;
        }
    } 


    return 0;
}
