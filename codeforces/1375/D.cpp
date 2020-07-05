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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    while (1) {
        bool found = 0;
        for (int i = 0; i < n; i++) {
            if (i == a[i]) {
                continue;
            } else {
                found = 1;
            }

            vector<int> cnt(n+1, 0);
            for (int j = 0; j < n; j++) {
                if (a[j] <= n) {
                    cnt[a[j]]++;
                }
            }

            int MEX = 0;
            while (cnt[MEX]) {
                MEX++;
            }

            if (MEX < n) {
                a[MEX] = MEX;
                ans.push_back(MEX);
            } else {
                for (int j = 0; j < n; j++) {
                    if (a[j] == i) {
                        ans.push_back(j);
                        a[j] = MEX;
                        ans.push_back(i);
                        a[i] = i;
                    }
                }
            }
        }
        if (!found) {
            break;
        }
    }

    /* for (int i = 0; i < n; i++) { */
    /*     cout << a[i] << " "; */
    /* } */ 
    /* cout << endl << "ANS" << endl; */

    cout << ans.size() << endl;
    for (int& x : ans) {
        cout << x+1 << " ";
    }
    cout << endl;

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
