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
    int n;
    cin >> n;
    vector<ar<int,3>> stays(n);
    for (int i = 0; i < n; i++) {
        cin >> stays[i][0] >> stays[i][1];
        stays[i][2] = i;
    }

    sort(stays.begin(), stays.end());
    vector<int> ans(n);

    multiset<ii, greater<ii>> hotels;
    int counter = 1;
    for (int i = 0; i < n; i++) {
        auto available = hotels.upper_bound(make_pair(stays[i][0], 0));

        if (available != hotels.end()) {
            ii hotel = *available;
            hotels.erase(available);
            hotels.insert(make_pair(stays[i][1], hotel.s));
            ans[stays[i][2]] = hotel.s;
        } 
        else {
            hotels.insert(make_pair(stays[i][1], counter)); 
            ans[stays[i][2]] = counter;
            counter++;
        }
    }

    cout << counter-1 << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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
