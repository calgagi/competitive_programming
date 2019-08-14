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
        int n;
        cin >> n;
        int r[n];
        int one_idx;
        for (int j = 0; j < n; j++) {
            cin >> r[j];
            if (r[j] == 1)
                one_idx = j;
        }
        bool forwards = true;
        for (int j = one_idx, x = 1; x < n; j = (j+1) % n, x++) {
            if (r[j] != x) {
                forwards = false;
                break;
            }
        }
        bool backwards = true;
        for (int j = one_idx, x = 1; x < n; x++) {
            if (r[j] != x) {
                backwards = false;
                break;
            }
            j--;
            if (j == -1)
                j = n-1;
        }
        if (forwards || backwards) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
