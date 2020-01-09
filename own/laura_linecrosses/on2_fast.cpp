// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;


long long num_intersects(vector<int>& p, vector<int>& q, int l, int r) {
    if (l >= r) 
        return 0;
    int m = l + (r - l) / 2;
    long long left_num = num_intersects(p, q, l, m), right_num = num_intersects(p, q, m+1, r);
    long long ans = 0;
    for (int i = l; i <= m; i++) {
        for (int j = m+1; j <= r; j++) {
            if (p[i] < p[j] && q[i] > q[j]) {
                ans++;
            } else if (p[i] > p[j] && q[i] < q[j]) {
                ans++;
            }
        }
    }
    return left_num + right_num + ans;
}

                    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> p(n), q(n);
    for (auto& i : p)
        cin >> i;
    for (auto& i : q)
        cin >> i;

    cout << num_intersects(p, q, 0, n-1) << endl;

    return 0;
}
