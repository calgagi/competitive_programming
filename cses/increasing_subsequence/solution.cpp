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

    vector<int> streaks(N, INT_MAX);
    int sz = 0;
    streaks[0] = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = sz; j >= 0; j--) {
            if (streaks[j] < A[i]) {
                if (j == sz) {
                    sz++;
                }
                streaks[j+1] = min(A[i], streaks[j+1]);
                break;
            }
        }
    }

    cout << sz << endl;

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
