// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

#define ll long long;
#define ull unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    
    int t; cin >> t;
    vector<long long> memo(1e5+5);
    memo[0] = 1;
    int max_so_far = 0;
    
    long long i2 = 0, i3 = 0, i5 = 0;
    while (t--) {
        int n; cin >> n;
        while (max_so_far < n-1) {
            long long i = min(memo[i2]*2LL, min(memo[i3]*3LL, memo[i5]*5LL));
            memo[++max_so_far] = i;
            if (i == memo[i2]*2LL) {
                i2++;
            } 
            if (i == memo[i3]*3LL) {
                i3++;
            }
            if (i == memo[i5]*5LL) {
                i5++;
            }
        }
        cout << memo[n-1] << endl;
    }
    return 0;
}

