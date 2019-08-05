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
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int a = 0;
    sort(t.begin(), t.end());
    int total_after = 0;
    for (int i : t) {
        if (total_after <= i) {
            a++;
            total_after += i;
        }
    }
    cout << a << endl;
    return 0;
}
