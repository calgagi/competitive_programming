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
    vector<int> c(150002, 0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c[x]++;
    }
    for (int i = 150000; i > 0; i--) {
        if (c[i] && c[i+1] == 0) {
            c[i+1]++;
            c[i]--;
        }
        if (c[i] > 1 && i-1 > 0 && c[i-1] == 0) {
            c[i]--;
            c[i-1]++;
        }
    }
    int r = 0;
    for (int i = 0; i <= 150001; i++)
        r += min(1, c[i]);
    cout << r << endl;

    return 0;
}
