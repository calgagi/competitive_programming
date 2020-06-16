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
    int n, x;
    cin >> n >> x;    
    vector<int> people(n);
    for (int& p : people) {
        cin >> p;
    }

    sort(people.begin(), people.end(), greater<int>());

    dd sum = 0, wealthy = x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += people[i];
        if (sum/(i+1) >= wealthy) {
            ans = i+1;
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
