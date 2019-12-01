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

    int n; cin >> n;
    int y[n];
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    int mi = INT_MAX, ma = INT_MIN;
    for (int i = 0; i < n; i++) {
        mi = min(mi, y[i]);
        ma = max(ma, y[i]);
    }
    cout << (mi+ma) / 2 << endl;

    return 0;
}
