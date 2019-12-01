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

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int n; cin >> n;
        int t = 0;
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            t += c;
        }
        cout << (t + n - 1) / n << endl;
    }

    return 0;
}
