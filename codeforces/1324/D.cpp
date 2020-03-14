// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

ll binary_search(vector<int>& s, int tar) {
    int l = 0, r = s.size()-1, res = 0;
    while (l <= r) {
        int m = l + (r-l) / 2;
        if (tar > s[m]) {
            res = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return tar>=s[0]?0:res+1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    } 
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = A[i] - B[i];
    }

    ll res = 0;
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        res += binary_search(diff, B[i]-A[i]);
    }

    cout << res << endl;

    return 0;
}
