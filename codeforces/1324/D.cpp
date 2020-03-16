// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

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

    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = A[i] - B[i];
    }

    sort(C.begin(), C.end()); 
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (C[i] >= 0) {
            continue;
        }
        int pos = lower_bound(C.begin(), C.end(), -c[i]+1) - C.begin();
        res += i - pos;
    }

    cout << res << endl;

    return 0;
}
