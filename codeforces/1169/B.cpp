// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> p;

bool check(int x, int y) {
    for (int i = 0; i < (int) p.size(); i++) {
        if (x == p[i].first || x == p[i].second || y == p[i].first || y == p[i].second)
            continue;
        return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n, m; cin >> n >> m;
    p.resize(m);
    for (auto& pp : p) {
        cin >> pp.first >> pp.second;
    }

    for (int x : {p[0].first, p[0].second}) {
        if (check(x, -1)) {
            cout << "YES\n";
            return 0;
        }
        for (int i = 1; i < m; i++) {
            if (!(x == p[i].first || x == p[i].second)) {
                if (check(x, p[i].first) || check(x, p[i].second)) {
                    cout << "YES\n";
                    return 0;
                }                    
                break;
            }
        }
    }
    cout << "NO\n";

    return 0;
}
