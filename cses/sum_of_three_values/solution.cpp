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

    map<int,int> seen;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int s = X - A[i] - A[j];
            if (seen.find(s) != seen.end()) {
                cout << seen[s]+1 << " " << i+1 << " " << j+1 << endl;
                return;
            }
        }
        seen[A[i]] = i;
    }

    cout << "IMPOSSIBLE" << endl;

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
