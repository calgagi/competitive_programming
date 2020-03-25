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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> color(n, 0);
    // if all the same, then 1
    bool o = 1;
    for (int i = 1; i < n; i++) {
        if (a[i-1] != a[i]) {
            o = 0;
            break;
        }
    }
    if (o) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    // if n = even, then 2
    if (!(n&1)) {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << ((i&1) ? 2 : 1) << " ";
        }
        cout << endl;
        return;
    }
        
    // if n can be made even, then 2
    o = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            o = 1;
            break;
        }
    }
    if (a[0] == a[n-1] || o) {
        cout << 2 << endl;
        o = 1;
        vector<int> c(n, 0);
        if (a[0] == a[n-1]) {
            c[0] = c[n-1] = 1;
            o = 0;
        } 
        c[0] = 1;
        for (int i = 1; i < n; i++) {
            c[i] = c[i-1]==1?2:1;
            if (a[i] == a[i-1] && o) {
                c[i] = c[i-1];
                o = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
        return;
    }     

    // else 3
    int counter = 1;
    cout << 3 << endl;
    for (int i = 0; i < n-1; i++) {
        cout << counter << " ";
        counter = counter+1;
        if (counter == 3) {
            counter = 1;
        }
    }
    cout << 3 << endl;
        

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
