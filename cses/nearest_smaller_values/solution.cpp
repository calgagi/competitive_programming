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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    stack<ii> s;
    vector<int> ans(N, 0);
    for (int i = N-1; i >= 0; i--) {
        while (!s.empty() && A[i] < s.top().f) {
            ans[s.top().s] = i+1;
            s.pop();
        }
        s.push({A[i], i});
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N-1 ? "" : " ");
    }
    cout << endl;

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
