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

    vector<string> winner = {"Ashishgup", "FastestFinger"};

    if (n == 1) {
        cout << winner[1] << endl;
    } 
    else if (n == 2) {
        cout << winner[0] << endl;
    }
    else if ((n & 1)) {
        cout << winner[0] << endl;
    }
    else {
        int count = 0;
        for (int i = 3; i*i <= n; i++) {
            if (n % i == 0 && ((i & 1) || ((n/i) & 1))) {
                count++;
            }
        }

        if (!count) {
            cout << winner[1] << endl;
            return;
        }
            
        if (n % 4 == 0) {
            cout << winner[0] << endl;
            return;
        }

        for (int i = 3; i*i <= n; i += 2) {
            if (n % i == 0) {
                cout << winner[0] << endl;
                return;
            }
        }

        cout << winner[1] << endl;
    }

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
