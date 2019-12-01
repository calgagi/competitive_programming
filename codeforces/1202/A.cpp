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

    int t; cin >> t;
    string x, y;
    for (int tc = 0; tc < t; tc++) {
        cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int i;
        for (i = 0; i < y.size(); i++) {
            if (y[i] == '1')
                break;
        }
        int j;
        for (j = i; j < x.size(); j++) {
            if (x[j] == '1')
                break;
        }
        cout << j-i << endl;
    }
    return 0;
}
