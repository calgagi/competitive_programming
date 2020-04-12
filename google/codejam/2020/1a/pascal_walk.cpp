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

const int M = 30;

void find_path(int n) {
    n -= 30;
    int c = 0;
    
    bool left = true;
    for (int i = 0; i < M; i++) {
        if ((n & (1 << i))) {
            if (left) {
                for (int j = 0; j <= i; j++) {
                    cout << i+1 << " " << j+1 << endl;
                }
            } else {
                for (int j = i; j >= 0; j--) {
                    cout << i+1 << " " << j+1 << endl;
                }
            }
            left = !left;
        } else {
            cout << i+1 << " " << (left ? 1 : i+1) << endl; 
            c++;
        }
    }

    for (int i = 0; c+i < 30; i++) {
        cout << M+i+1 << " " << (left ? 1 : M+i+1) << endl;
    }
    return;
}

void solve() {
    int n;
    cin >> n;
    cout << endl;
    if (n <= 30) {
        for (int i = 0; i < n; i++) {
            cout << i+1 << " " << 1 << endl;
        }
    } else {
        find_path(n);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
