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

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    int sum = 0, ans = 0;
    for (int b = 0, e = 0; e < N; e++) {
        sum += A[e];
        while (sum >= X) {
            if (sum == X) {
                ans++;
            }
            sum -= A[b];
            b++;
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
