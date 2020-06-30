/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

ll test(vector<int>& A, ll m, ll K) {
    ll cur = 0, sections = 1, ans = 0;
    for (int& a : A) {
        if (cur + a <= m) {
            cur += a;
        } else if (a <= m) {
            cur = a;
            sections++;
        } else {
            return LLONG_MAX;
        }
        ans = max(cur, ans);
    }

    if (sections > K) {
        return LLONG_MAX;
    }
    
    return ans;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    ll left = 1, right = 1e15, ans = LLONG_MAX;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll result = test(A, mid, K);
        if (result == LLONG_MAX) {
            left = mid+1;
        } else {
            ans = min(ans, result);
            right = mid-1;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
