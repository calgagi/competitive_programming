// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<long long> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());

    vector<long long> ff = f;

    // calculate max
    int mx = 1;
    ff[0]--;
    for (int i = 1; i < n; i++) {
        if (ff[i]-1 > ff[i-1]) {
            ff[i]--;
            mx++;
        } else if (ff[i] > ff[i-1]) {
            mx++;
        } else if (ff[i]+1 > ff[i-1]) {
            ff[i]++;
            mx++;
        } else {
            ff[i]++;
        }
    }

    // calculate min
    int mn = 1;
    f[0]++;
    for (int i = 1; i < n; i++) {
        if (f[i-1] == f[i]-1) {
            f[i]--;
        } else {
            if (f[i] == f[i-1])
                continue;
            f[i]++;
            if (f[i] == f[i-1])
                continue;
            mn++;
        }
    }
    cout << mn << " " << mx << endl;
            



    return 0;
}
