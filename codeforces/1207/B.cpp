// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m; cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    vector<pair<int, int> > r;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]) {
                b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
                r.push_back({i+1, j+1});
            }
        }
    }
    bool good = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                good = false;
                break;
            }
        }
    }
    if (good) {
        cout << r.size() << endl;
        for (int i = 0; i < r.size(); i++) {
            cout << r[i].first << " " << r[i].second << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
