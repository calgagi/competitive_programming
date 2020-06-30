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
    int N, K;
    cin >> N >> K;
    vector<ii> movies(N);
    for (ii& movie : movies) {
        cin >> movie.f >> movie.s;
    }

    sort(movies.begin(), movies.end(), [&](const ii& a, const ii& b) {
        return a.s < b.s;
    });

    multiset<int, greater<int>> q;
    for (int i = 0; i < K; i++) {
        q.insert(0);
    }

    int ans = 0;
    for (ii& movie : movies) {
        auto person = q.lower_bound(movie.f);
        if (person != q.end()) {
            q.erase(person);
            q.insert(movie.s);
            ans++;
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
