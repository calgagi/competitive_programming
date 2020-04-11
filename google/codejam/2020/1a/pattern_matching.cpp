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

const int MAX_P = 100;
const int MAX_N = 50;

void go_print(vector<char>& x, string& mid) {
    int n = x.size();
    bool f = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] != '-') {
            cout << x[i];
        } else if (f) {
            cout << mid;
            f = 0;
        }
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<char> x(MAX_P*MAX_N+10, '-');
    int L = MAX_P*MAX_N+10;
    vector<string> solid;
    string mid = "";
    for (auto& s : a) {
        int l = s.length();
        // Place backwards and forwards characters
        int m = 0, i, j;
        for (i = 0; i < l && s[i] != '*'; i++) {
            if (x[i] == '-') {
                x[i] = s[i];
                m = max(i+1, m);
            } else if (x[i] != s[i]) {
                cout << "*" << endl;
                return;
            }
        }
        for (j = 0; j < l && s[l-1-j] != '*'; j++) {
            if (x[L-1-j] == '-') {
                x[L-1-j] = s[l-1-j];
            } else if (x[L-1-j] != s[l-1-j]) {
                cout << "*" << endl;
                return;
            }
        }
        j = l-1-j;
        if (i > j) {
            solid.push_back(s);
        } else {
            // Place middle characters
            for (int k = i; k <= j; k++) {
                if (s[k] != '*') {
                    mid += s[k];
                }
            }

        }
    }

    // Either need to construct string or check if solid works
    if (solid.empty()) {
        go_print(x, mid);
        return;
    } else {
        string d = solid[0];
        for (auto& s : solid) {
            if (s != d) {
                cout << "*" << endl;
                return;
            }
        }
        string left = "", right = "";
        for (int i = 0; i < L && x[i] != '-'; i++) {
            left += x[i];
        }
        for (int i = L-1; i >= 0 && x[i] != '-'; i--) {
            right += x[i];
        }
        reverse(right.begin(),right.end());
        if (left != right || left != d) {
            cout << "*" << endl;
            return;
        } else {
            cout << d << endl;
            return;
        }
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
