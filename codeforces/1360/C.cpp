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
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    vector<int> odd, even;

    for (int i = 0; i < n; i++) {
        if ((a[i] & 1)) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }

    if (!(odd.size() & 1) && !(even.size() & 1)) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < (int) even.size(); i++) {
        for (int j = 0; j < (int) odd.size(); j++) {
            if (abs(odd[j]-even[i]) == 1) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
